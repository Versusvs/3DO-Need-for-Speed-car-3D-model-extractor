#include "StdAfx.h"
#include "SHPM extract.h"
#include "Form1.h"


#if 1;
int Extract3DOSHPM(unsigned int offsetSHPMabs, unsigned int polygonTexture, const wchar_t *path1, bool alltex1) {
//cout << "Extracting SHPM " << textN << " " << infilename << " " << type << " " << lod << " " << hex << offsetSHPMabs << " " << polygonTexture <<"\n";
int temp, offset2texture, offsetABS;
int nextoff = 0;

// Open file
ifstream inputfile;
inputfile.open(path1, ios::binary|ios::in);

//FILE *infile;
//infile = fopen(infilename, "rb");
inputfile.seekg (offsetSHPMabs, inputfile.beg);

//FILE *outf;
//outf = fopen(debugfilepath,"w");

//fclose(outf);
//System::Windows::Forms::Label^  label7;
//label7->Text = "offsetSHPMabs = " + offsetSHPMabs.ToString();

#if 1;
//fseek(infile, offsetSHPMabs, SEEK_SET);
inputfile.read((char *)&temp,sizeof(temp)); // SHPM
inputfile.read((char *)&temp,sizeof(temp));	// SHPM size
inputfile.read((char *)&temp,sizeof(temp));	// Number of objects in the directory
inputfile.read((char *)&temp,sizeof(temp)); // 'SPoT'
	

inputfile.read((char *)&temp,sizeof(temp));
inputfile.read((char *)&temp,sizeof(temp));
offset2texture = Swap4Bytes(temp);
//cout << "PolygonN " << polygonTexture <<"\n";
//cout << "Local offset within the SHPM to texture " << hex << offset2texture << "\n";

if (polygonTexture > 0) {
	for (int i = 0; i<polygonTexture; i++) {
		inputfile.read((char *)&temp,sizeof(temp));
		inputfile.read((char *)&temp,sizeof(temp));
		offset2texture = Swap4Bytes(temp);
//		cout << "PolygonN " << polygonTexture <<"\n";
//		cout << "Local offset within the SHPM to texture " << hex << offset2texture << "\n";
	}
}

	inputfile.read((char *)&temp,sizeof(temp)); // Read next entry for PDAT size calculations
	inputfile.read((char *)&temp,sizeof(temp)); // Read next entry for PDAT size calculations
	nextoff = Swap4Bytes(temp);

offsetABS = offset2texture+offsetSHPMabs;
//cout << "offsetABS 0x" << hex << offsetABS << "\n";


// Seek corresponding texture
inputfile.seekg (offsetABS, inputfile.beg);
//fseek(infile, offsetABS, SEEK_SET);

// Read pixel data header
unsigned short int ccbtype, height, width, shorttemp, pdatSize, arrsize;
short int off2palette;

inputfile.read((char *)&shorttemp,sizeof(shorttemp));
//fread(&shorttemp, 2, 1, infile);
ccbtype =  Swap2Bytes(shorttemp);
//cout << "ccbtype 0x" << hex << ccbtype << "\n";

inputfile.read((char *)&shorttemp,sizeof(shorttemp));
off2palette = Swap2Bytes(shorttemp);
//System::Windows::Forms::Label^  label8;
//label8->Text = "off2palette = " + off2palette.ToString();
//System::String^ a = "lol123";
//richTextBox1->AppendText(a+"\n");

//cout << "off2palette 0x" << hex << off2palette << "\n";

inputfile.read((char *)&shorttemp,sizeof(shorttemp));
width = Swap2Bytes(shorttemp);

inputfile.read((char *)&shorttemp,sizeof(shorttemp));
height = Swap2Bytes(shorttemp);

inputfile.read((char *)&temp,sizeof(temp)); // PREAMBLE word or CCB flags??????
inputfile.read((char *)&temp,sizeof(temp));
//cout << "temp = " << hex <<  temp <<"\n";
//cout << "height = " << dec <<  height <<"\n";
//cout << "width = " << dec << width <<"\n\n";


// Read pixel data
inputfile.seekg (offsetABS+0x10, inputfile.beg);


//fseek(infile, offsetABS+0x10, SEEK_SET);
pdatSize = off2palette - 0x10;
arrsize = pdatSize/4;

// MAKE if off2palette < 0
if (off2palette < 0) {
	pdatSize = nextoff - offset2texture - 0x10;
	// Read palette from above
	arrsize = pdatSize/4;
	}

int *arrayPDAT = new int [arrsize];

for (int k=0; k < arrsize; k++) {
	inputfile.read((char *)&temp,sizeof(temp));
	arrayPDAT[k] = Swap4Bytes(temp);
//	cout << "arrayPDAT = 0x" << hex <<  arrayPDAT[k] <<" \n";
	}

// Read palette data
int *arrayPLUT = new int [16];

if (off2palette < 0) {
	inputfile.seekg (offsetABS - abs(off2palette) + 0x10, inputfile.beg);
	} else {

inputfile.read((char *)&temp,sizeof(temp)); // skip
inputfile.read((char *)&temp,sizeof(temp)); // skip
inputfile.read((char *)&temp,sizeof(temp)); // skip
inputfile.read((char *)&temp,sizeof(temp)); // skip
}

for (int k1=0; k1 < 16; k1++) {
	inputfile.read((char *)&temp,sizeof(temp)); // skip
	arrayPLUT[k1] = Swap4Bytes(temp);
//	cout << "arrayPLUT = 0x" << hex <<  arrayPLUT[k1] <<" \n";
	}

//cout << " \n";

// Make new texture file
char bmpname[40], tmpbmp[40];
int temp111;

temp111 = polygonTexture;

itoa(temp111, bmpname, 10);
FILE* cel;

if (alltex1 == 1) {
	strcpy(tmpbmp, "\Object3DTextures\\All textures\\Tex");
	} else {
	strcpy(tmpbmp, "\Object3DTextures\\Tex");
	}
//strcat(bmpname, ".cel");
strcat(tmpbmp, bmpname);
//cout << tmpbmp << endl;

cel = fopen(tmpbmp, "wb");
fclose(cel);
cel = fopen(tmpbmp, "ab");

// Write all data to file
// Generate and write CCB header
temp = 0x43434220;
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel); 
temp = 0x50000000;
fwrite(&temp, 4, 1, cel); 
temp = 0;
fwrite(&temp, 4, 1, cel);
temp = 0x4000;
fwrite(&temp, 4, 1, cel);
temp = 0;
for (int k2=0; k2 < 12; k2++) {
	fwrite(&temp, 4, 1, cel);
	}
if ((ccbtype==0x500)||(ccbtype==0x5FF)) {// Set another PREAMBLE word for some textures
	temp = 0x00000015;	
	} else {
temp = 0x34D34924; // Common PREAMBLE word
	}
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel);
temp = 0;
fwrite(&temp, 4, 1, cel);
temp = width;			// width
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel);
temp = height;			// height
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel);
temp = 0x50444154;
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel);
temp = pdatSize + 8; // 8 - occupied by PDAT and offset to PLUT
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel);
// Write PDAT data
for (int i1=0; i1 < arrsize; i1++) {
	temp = Swap4Bytes(arrayPDAT[i1]);
	fwrite(&temp, 4, 1, cel);
	}


// Generate and write PLUT header
temp = 0x504C5554;
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel); 
temp = 0x0000004C;
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel); 
temp = 0x00000020;
temp = Swap4Bytes(temp);
fwrite(&temp, 4, 1, cel);

// Write PLUT data
for (int i2=0; i2 < 16; i2++) {
	temp = Swap4Bytes(arrayPLUT[i2]);
	fwrite(&temp, 4, 1, cel);
	}



// Close new file
fclose(cel);
inputfile.close();
//fclose(infile);
delete[]arrayPDAT;
delete[]arrayPLUT;
#endif;
return 0;
}
#endif;