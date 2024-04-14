#pragma once
#include "stdafx.h"
#include <iostream>
#include <iso646.h>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <conio.h>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
#include <vcclr.h>
#include "resource.h"
#include <bitset>
#include "SHPM extract.h"
//#include <atlstr.h>
#include <msclr\marshal_cppstd.h>
//#include <msclr/marshal.h>
#include <direct.h>
#include <iomanip>
//#include <atlstr.h>
#include <sstream>

#include <vector>
#include <list>
#include <math.h>
#include <algorithm>

using namespace std;


#define Swap4Bytes(val) val = ( (((val) >> 24) & 0x000000FF) | (((val) >> 8) & 0x0000FF00) | (((val) <<  8) & 0x00FF0000) | (((val) << 24) & 0xFF000000) )
#define Swap8Bytes(val) ( (((val) >> 56) & 0x00000000000000FF) | (((val) >> 40) & 0x000000000000FF00) | (((val) >> 24) & 0x0000000000FF0000) | (((val) >>  8) & 0x00000000FF000000) | (((val) <<  8) & 0x000000FF00000000) | (((val) << 24) & 0x0000FF0000000000) | (((val) << 40) & 0x00FF000000000000) | (((val) << 56) & 0xFF00000000000000) )
#define Swap2Bytes(val) ( (((val) >> 8) & 0x00FF) | (((val) << 8) & 0xFF00) )

const int SCALE3DObjUVMap = 75; // Scale for the 3D objects (UV mapping)
const int SCALE3D = 1500; // Scale for the 3D objects
#define degreesToRadians(angleDegrees) ((angleDegrees) * pi / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / pi)
const double pi = 3.1415926535897932384626433832795;
#define F_EPS 1e-4


typedef struct {		// Polygon struct for 3DO 3D object
      unsigned int indexN; 
      unsigned int vertex1; 
      unsigned int vertex2;
      unsigned int vertex3;
      unsigned int vertex4;
	  char polytype;
	} poly3DO_t;

extern int Extract3DOSHPM(unsigned int offsetSHPMabs, unsigned int polygonTexture, const wchar_t *path1, bool alltex1);

namespace Carextractor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::Label^  label1;

	private: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;

	public: System::Windows::Forms::Label^  label8;

	public: 
	protected private: 


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(31, 469);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Load car";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->Column1, 
				this->Column2});
			this->dataGridView1->Location = System::Drawing::Point(322, 30);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(453, 462);
			this->dataGridView1->TabIndex = 2;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Name";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Value";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 200;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 526);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(145, 322);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Car LOD selector";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"LOD 1", L"LOD 2", L"LOD 3"});
			this->comboBox1->Location = System::Drawing::Point(148, 338);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(31, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(71, 188);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(74, 214);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"label5";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(47, 399);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(319, 495);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(590, 523);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 13;
			this->label8->Text = L"label8";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1017, 548);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Need for Speed 3DO and PC car extractor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


#if 0;
class Vector31{
public:
  float x,y,z;
  Vector31(){}
  Vector31(float _x, float _y, float _z){x=_x; y=_y; z=_z;}
  float len2(){return x*x + y*y + z*z;}
  float len(){return sqrt(len2());}
  void normalize(){float l=sqrt(x*x+y*y+z*z); x/=l; y/=l; z/=l;}
  float operator * (Vector31 arg){return x*arg.x + y*arg.y + z*arg.z;}
  Vector31 operator = (Vector31 src){x=src.x; y=src.y; z=src.z; return *this;}
  Vector31 operator + (Vector31 arg){Vector31 tmp(x+arg.x, y+arg.y, z+arg.z); return tmp;}
  Vector31 operator - (Vector31 arg){Vector31 tmp(x-arg.x, y-arg.y, z-arg.z); return tmp;}
  Vector31 operator * (float l){Vector31 tmp(x*l, y*l, z*l); return tmp;} //scalar multiply
};


int find_intersection2(Vector31 ray_st, Vector31 ray_dir, Vector31 sp_cen, float sp_rad, Vector31 &res1, Vector31 &res2){
  Vector31 middle; //middle point between intersections
  Vector31 dist; //vector from center of sphere to ray start
  Vector31 dpos; //vector from ray_st to sp_cen
  float len2; //square of distance from center of sphere to ray
  ray_dir.normalize();
  sp_rad *= sp_rad;
  
  dpos = sp_cen - ray_st;
  middle = ray_st + ray_dir*(ray_dir*dpos);
  len2 = (middle - sp_cen).len2();
  
  if(len2 > sp_rad)return 0;
  if(fabs( len2 - sp_rad )<F_EPS){
    res1 = middle;
    return 1;
  }
  len2 = sqrt(sp_rad - len2);
  //now len2 is distance, not its square
  res1 = middle - ray_dir*len2;
  res2 = middle + ray_dir*len2;
  return 2;
}
#endif;




	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
unsigned int buffer = 0;
unsigned int chunk1Offset, chunk2Offset, chunk3Offset, chunk4Offset = 0;
unsigned int chunk1Length = 0;
unsigned int size1, size2, size3, size4, size5, size6, size7, size8, size9 = 0;
unsigned int off1,  off2, off3, off4, off5, off6, off7, off8, off9 = 0;
unsigned char triangle; 
unsigned char quadrangle; 
unsigned char quadrNull; 
bool flag3DO = false;
FILE *outf;
unsigned int ori3off = 0;
unsigned int shpmoff = 0;
unsigned int chunkoff = 0;
float angle = 0;
bool alltex = 0;
//Vector31 r1, r2;

FILE *outf111;
char *outfilename111;
// Rewrite Objects file for future use
outfilename111 = "Object3D.obj";
outf111 = fopen(outfilename111,"w");
fclose(outf111);

outfilename111 = "Obj3D.mtl";
outf111 = fopen(outfilename111,"w");
fclose(outf111);

    int check; 
    char* dirname = "Object3DTextures"; 
    check = _mkdir(dirname);

    dirname = "Object3DTextures\\All textures"; 
    check = _mkdir(dirname);

pin_ptr<const wchar_t> dir = PtrToStringChars(openFileDialog1->FileName); 
const wchar_t *dir1 = dir;                     // <-- Unnecessary, but to be completely verbose
	openFileDialog1->RestoreDirectory = true;

	      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
      {
         // do your stuff
ifstream infile;



pin_ptr<const wchar_t> convertedValue = PtrToStringChars(openFileDialog1->FileName); 
const wchar_t *path = convertedValue;                     // <-- Unnecessary, but to be completely verbose
//infile.open("c:\\11a", ios::binary|ios::out);
//infile.open("c:\\0", ios::binary|ios::out);
infile.open(path, ios::binary|ios::in);
    infile.seekg (0, infile.end);
    int length = infile.tellg();
    infile.seekg (0, infile.beg);

//label9->Text = "Filesize = " + length.ToString();
int lod = comboBox1->SelectedIndex;
//label2->Text = System::Convert::ToString(lod);

if (lod==-1) return;

// Seek input file for selected LOD ORI3 (for 3DO)
infile.read((char *)&buffer,sizeof(buffer));
infile.read((char *)&buffer,sizeof(buffer));

if (buffer == 4) { // PC file version
	Form1::Text = "Need for Speed 3DO and PC car extractor v0.1 (Vas.1987)     " + " PC file version ";
	} else

if ((buffer == 0x4000000)||(buffer == 0x3000000)) { // 3DO file version
	flag3DO = true;
	Form1::Text = "Need for Speed 3DO and PC car extractor v0.1 (Vas.1987)     " + " 3DO file version ";
	}


infile.read((char *)&buffer,sizeof(buffer));

for (int k=0; k<lod; k++) {
infile.read((char *)&buffer,sizeof(buffer));
}
if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
chunkoff = buffer;
label3->Text = "chunkoff = " + chunkoff.ToString();

// Jump to selected LOD.
infile.seekg (buffer, infile.beg);
//infile.seekg (buffer, infile.beg);
infile.read((char *)&buffer,sizeof(buffer));
infile.read((char *)&buffer,sizeof(buffer));
infile.read((char *)&buffer,sizeof(buffer));
// Read ORI3 offset
if (flag3DO == true) {ori3off = Swap4Bytes(buffer);}
// Read SHPM offset
infile.read((char *)&buffer,sizeof(buffer));
if (flag3DO == true) {shpmoff = Swap4Bytes(buffer);}

//
label4->Text = "ori3off = " + ori3off.ToString();
label5->Text = "shpmoff = " + shpmoff.ToString();

//***********************************************************************************
///////////////////// NOW I CAN READ ORI3 SECTION //////////////////////////
unsigned int size8, offset8, size10, offset10, size5, offset5, sizeORI3, size11, offset11, offset6;
int temp11 = 0;

infile.read((char *)&temp11,sizeof(buffer));
infile.read((char *)&temp11,sizeof(buffer));

sizeORI3 = Swap4Bytes(temp11);
//label6->Text = "sizeORI3 = " + sizeORI3.ToString();

infile.read((char *)&temp11,sizeof(buffer));
infile.read((char *)&temp11,sizeof(buffer));
infile.read((char *)&temp11,sizeof(buffer));
size8 = Swap4Bytes(temp11); 
//label6->Text = "size8 = " + size8.ToString();
infile.read((char *)&temp11,sizeof(buffer));
offset8 = Swap4Bytes(temp11);
//cout << "size8 = " << hex << size8 << "\n";
//cout << "offset8 = " << hex << offset8 << "\n";
infile.read((char *)&temp11,sizeof(buffer));
infile.read((char *)&temp11,sizeof(buffer));
infile.read((char *)&temp11,sizeof(buffer));
size10 = Swap4Bytes(temp11); 
infile.read((char *)&temp11,sizeof(buffer));
offset10 = Swap4Bytes(temp11);
//cout << "size10 = " << hex << size10 << "\n";
//cout << "offset10 = " << hex << offset10 << "\n";
for (int i=0; i < 11; i++) {
	infile.read((char *)&temp11,sizeof(buffer));
	}
infile.read((char *)&temp11,sizeof(buffer));
size5 = Swap4Bytes(temp11);
infile.read((char *)&temp11,sizeof(buffer));
offset5 = Swap4Bytes(temp11);
//cout << "size5 = " << hex << size5 << "\n";
//cout << "offset5 = " << hex << offset5 << "\n";
infile.read((char *)&temp11,sizeof(buffer));
size11 = size10;
infile.read((char *)&temp11,sizeof(buffer));
offset11 = Swap4Bytes(temp11);
//cout << "size11 = " << hex << size11 << "\n";
//cout << "offset11 = " << hex << offset11 << "\n";
infile.read((char *)&temp11,sizeof(buffer)); // size6
infile.read((char *)&temp11,sizeof(buffer));
offset6 = Swap4Bytes(temp11);
//cout << "offset6 = " << hex << offset6 << "\n";
infile.read((char *)&temp11,sizeof(buffer));// size7
infile.read((char *)&temp11,sizeof(buffer));// offset7
infile.read((char *)&temp11,sizeof(buffer));// 0x118 or 0x120

// Read all blocks and make 3D geometry for export.///////////
// Read block 8 (vertexes X, Z, Y)
infile.seekg (chunkoff+offset8+0x10, infile.beg); // Set to the start of 8th block
//label6->Text = "start of 8th block = " + (chunkoff+offset8+0x10).ToString();
//label6->Text = "offset8 = " + offset8.ToString();
//fseek(famFile3, offset2ORI3abs+offset8, SEEK_SET); // Set to the start of 8th block
//cout << "offset2ORI3abs+offset8 = 0x" << hex << offset2ORI3abs+offset8 << "\n";

float *arrayX = new float [size8];
float *arrayZ = new float [size8];
float *arrayY = new float [size8];
int tmp1 = 0;

#if 1;

#if 1; // rotation

for (int x=0; x<size8; x++) {
infile.read((char *)&temp11,sizeof(buffer)); // X coord.
			arrayX[x] = Swap4Bytes(temp11);
//			cout << "+arrayX ["<< x << "]= " << dec << arrayX[x] << "\n";
infile.read((char *)&temp11,sizeof(buffer)); // Z coord.
			arrayZ[x] = Swap4Bytes(temp11);
//			cout << "+arrayZ ["<< x << "]= " << dec << arrayZ[x] << "\n";
infile.read((char *)&temp11,sizeof(buffer)); // Y coord.
			tmp1 = Swap4Bytes(temp11);
			arrayY[x] = -tmp1;
//			cout << "+arrayY ["<< x << "]= " << dec << arrayY[x] << "\n";
}

for (int a=0; a<size8; a++) {
	if ((arrayX[a]==0)&&(arrayY[a]==0)) continue;

/// Find new vector dir for current point.
// Tan alfa = Y/X. Alfa = arctg(Y/X).
float alfa = 0;
///alfa = radiansToDegrees(atan(arrayY[a]/arrayX[a]));

///find_intersection2(Vector31(0, 0, (float)arrayZ[a]),													// Vector start
///				   Vector31(cos(degreesToRadians(alfa+angle)), sin(degreesToRadians(alfa+angle)), 0),	// Vector direction
///				   Vector31(0, 0, (float)arrayZ[a]),													// Sphere center
///				   sqrt((float)arrayX[a]*(float)arrayX[a]+(float)arrayY[a]*(float)arrayY[a]),			// Sphere radius
///				   r1, r2);																				// Result points
///(float)arrayX[a] = r2.x;
///(float)arrayY[a] = r2.y;
}
#endif;// rotation


// Read block 10 (polygons binded by vertices)
poly3DO_t* polys = new poly3DO_t[size10];
int *arrayTextureN = new int [size10];
	int	type = 1; // SHPM for 3D object
	int lod1 = 1; // LOD
	char ptype;

for (int g=0; g<size10; g++) {
infile.read((char *)&ptype,1); // polygon property. 0 - quadrangle, 1 - triangle
		polys[g].polytype = ptype;
infile.read((char *)&temp11,3); // skip
infile.read((char *)&temp11,sizeof(buffer)); // polygon index #
		polys[g].indexN = Swap4Bytes(temp11);
infile.read((char *)&temp11,sizeof(buffer)); // vertex 1 index
		polys[g].vertex1 = Swap4Bytes(temp11);
infile.read((char *)&temp11,sizeof(buffer)); // vertex 2 index
		polys[g].vertex2 = Swap4Bytes(temp11);
infile.read((char *)&temp11,sizeof(buffer)); // vertex 3 index
		polys[g].vertex3 = Swap4Bytes(temp11);
infile.read((char *)&temp11,sizeof(buffer)); // vertex 4 index
		polys[g].vertex4 = Swap4Bytes(temp11);
}


#if 0;
for (int g1=0; g1<size10; g1++) {
	cout << "indexN = "<< polys[g1].indexN << "\n";
	cout << "vertex 1 = "<< polys[g1].vertex1 << "\n";
	cout << "vertex 2 = "<< polys[g1].vertex2 << "\n";
	cout << "vertex 3 = "<< polys[g1].vertex3 << "\n";
	cout << "vertex 4 = "<< polys[g1].vertex4 << "\n";
	}
#endif;


// Read block 5 ('NON-SORT'....)
for (int h=0; h<size5; h++) {
infile.read((char *)&temp11,sizeof(buffer)); // skip
infile.read((char *)&temp11,sizeof(buffer)); // skip
infile.read((char *)&temp11,sizeof(buffer)); // skip
infile.read((char *)&temp11,sizeof(buffer)); // skip
infile.read((char *)&temp11,sizeof(buffer)); // skip
infile.read((char *)&temp11,sizeof(buffer)); // skip
infile.read((char *)&temp11,sizeof(buffer)); // skip
	}

// Read block 11 (in case of common 3D objects, reading is unnecessary)

// Must read !ori section.
infile.seekg (chunkoff+shpmoff, infile.beg);
//label6->Text = "SHPM off = " + (chunkoff+shpmoff).ToString();
//fseek(famFile3, offsetSHPMabs, SEEK_SET); // Jump 2 SHPM to read !ori.

// Read file until !ori is reached. Then read it's offset.
int ori = 0;
unsigned int off2ori = 0;

for (int i3 = 0; i3 < 128; i3++) {
infile.read((char *)&temp11,sizeof(buffer));
	ori = temp11;
	if (ori == 0x69726F21) break;
	}

infile.read((char *)&temp11,sizeof(buffer));
off2ori = Swap4Bytes(temp11);
//cout << "off2ori 0x" << hex << off2ori <<"\n";


// Jump to !ori and skip it's header (+ 0x40)
infile.seekg (chunkoff+shpmoff+off2ori+0x40, infile.beg);
//label6->Text = "off2ori = " + (chunkoff+shpmoff+off2ori+0x40).ToString();
//fseek(famFile3, offsetSHPMabs + off2ori + 0x40, SEEK_SET); // Jump 2 !ori and skip 0x40.

// Read polygon number then read texture number located in SHPM.
int subchunk = 0;

//subchunk = remainder;
for (int g1=0; g1<size10; g1++) {
	infile.read((char *)&temp11,sizeof(buffer));
	infile.read((char *)&temp11,sizeof(buffer));
	arrayTextureN[g1] = Swap4Bytes(temp11);
	// Read SHPM section and extract textures.
unsigned int offsetSHPM = chunkoff+shpmoff;
const wchar_t *path1 = path;
	Extract3DOSHPM(offsetSHPM, arrayTextureN[g1], path1, alltex); // TURN ON!!!
}

// Extract all textures from SHPM!
// Generate path2
//System::String^ path2 = System::IO::Path::GetDirectoryName(openFileDialog1->FileName) + "\\Object3DTextures\\All textures";
//label7->Text = path2;
//msclr::interop::marshal_context oMarshalContext;
//const char* filePath1 = oMarshalContext.marshal_as<const char*>(path2);
//System::String^ a;
//char texx[40];
//richTextBox1->AppendText(a+"\n");


infile.seekg (chunkoff+shpmoff, infile.beg);
alltex = 1;
unsigned int offsetSHPM1 = chunkoff+shpmoff;
const wchar_t *path11 = path;
	infile.read((char *)&temp11,sizeof(buffer));
	infile.read((char *)&temp11,sizeof(buffer));
	infile.read((char *)&temp11,sizeof(buffer)); // N of entries
	temp11 = Swap4Bytes(temp11);
	label7->Text = "SHPM textures N = " + temp11.ToString();

	for (int kf=0; kf<(temp11-1); kf++) {
		Extract3DOSHPM(offsetSHPM1, kf, path11, alltex);
		}
//Extract3DOSHPM(offsetSHPM1, 36, path11, alltex);
alltex = 0;
//label7->Text = "SHPM off = " + (chunkoff+shpmoff).ToString();



//outf = fopen(filePath,"w");

//fclose(outf);

////////******************/////////////////////////**********************///////////////////
// 1) Write vertexes from block 8 to the obj file.
//int temp, offset, offset2, offset2ORIP, tmp;
char bmpname[40], tmpbmp[40];

FILE *outf;
int textN = 0;
float X, Y, Z = 0;
int vtcounter  = 1; 
int	counter = 0;
int size13DObj=0;
int size83DObj=0;
int vt3DOcounter=1;

itoa(textN, bmpname, 10);
strcpy(tmpbmp, "Object3D.obj");
//cout << tmpbmp << "\n";


//outf = fopen(tmpbmp, "wb");// Blank it.
//fclose(outf);

outf = fopen(tmpbmp,"a");
fwrite("# 3D object\n",12,1,outf);
fprintf(outf, "mtllib Obj3D.mtl\n\n");
//fprintf(outf, "o 3DObject");
fprintf(outf, "o 3DObject%f\n", X);
//fprintf(outf, "%d\n", BitmapN);

// Write vertex coords.
for (int s=0; s<size8; s++) {
	fwrite("v ",2,1,outf); //1
	fprintf(outf, "%f ", (float)arrayX[s]/SCALE3D + (float)X);
	fprintf(outf, "%f ", (float)arrayZ[s]/SCALE3D + (float)Z);
	fprintf(outf, "%f ", (float)arrayY[s]/SCALE3D + (float)Y);
///	fprintf(outf, "%f ", (float)arrayX[s]);
///	fprintf(outf, "%f ", (float)arrayZ[s]);
///	fprintf(outf, "%f ", (float)arrayY[s]);
	fwrite("\n",1,1,outf);// New line
}
fwrite("\n",1,1,outf);// New line

//fclose(outf);


// Write vt params. There are 4 vertices. Max uv coord is 1.0!
for (int i4 = 0; i4<size10; i4++) {
		if (polys[i4].polytype == 1) {
			fprintf(outf, "\n");
			fprintf(outf, "vt 0.000000 1.000000\n");
			fprintf(outf, "vt 1.000000 1.000000\n");
			fprintf(outf, "vt 0.000000 0.000000\n");
		} else {
fprintf(outf, "\n");
fprintf(outf, "vt 0.000000 1.000000\n");
fprintf(outf, "vt 1.000000 1.000000\n");
fprintf(outf, "vt 1.000000 0.000000\n");
fprintf(outf, "vt 0.000000 0.000000\n");
		}
}

// Write polygons
// Draw size 10 polygons.
{
	for (int b=0; b<size10; b++) {
			fprintf(outf, "usemtl %d\n", arrayTextureN[b]);
	fwrite("f ",2,1,outf);
#if 0;		
		fprintf(outf, "%d %d %d %d \n", 
		polys[b].vertex1+1 + counter, 
		polys[b].vertex2+1 + counter,
		polys[b].vertex3+1 + counter,
		polys[b].vertex4+1 + counter);
#endif;
#if 1;
		if (polys[b].polytype == 1) {
		fprintf(outf, "%d/%d %d/%d %d/%d\n", 
		polys[b].vertex1+1 + counter, vtcounter,
		polys[b].vertex2+1 + counter, vtcounter+1,
		polys[b].vertex3+1 + counter, vtcounter+2);
		vtcounter += 3;
		} else {
		fprintf(outf, "%d/%d %d/%d %d/%d %d/%d\n", 
		polys[b].vertex1+1 + counter, vtcounter,
		polys[b].vertex2+1 + counter, vtcounter+1,
		polys[b].vertex3+1 + counter, vtcounter+2,
		polys[b].vertex4+1 + counter, vtcounter+3);
#endif;

	vtcounter += 4;
		}
	}
}
//counter += 4;
vt3DOcounter = vtcounter;
//size13DObj = size13DObj+size1;
size83DObj = size83DObj+size8; 
fclose(outf);


// Make material file
FILE *mtlfile;

mtlfile = fopen("Obj3D.mtl","a");

for (int t=0; t<size10; t++) {
//fprintf(mtlfile, "newmtl %d\n", arrayTextureN[t]);
	if (subchunk==1) {
	fprintf(mtlfile, "newmtl %d\n", ((arrayTextureN[t]+111)*10));
	fprintf(mtlfile, "map_Kd ThreeDO3DobjTextures\\2\\Tex%d.bmp\n", ((arrayTextureN[t]+111)*10));
	} else {
	fprintf(mtlfile, "newmtl %d\n", arrayTextureN[t]);
	fprintf(mtlfile, "map_Kd ThreeDO3DobjTextures\\Tex%d.bmp\n", arrayTextureN[t]);
	}
}
fclose(mtlfile);
////////******************/////////////////////////**********************///////////////////
//fclose(famFile3);
delete []polys;  
//return size83DObj;
//***********************************************************************************
#endif;


#if 0;
infile.read((char *)&buffer,sizeof(buffer));
infile.read((char *)&buffer,sizeof(buffer));

label1->Text = "buffer = " + buffer.ToString();

if (buffer == 4) { // PC file version
	Form1::Text = "Need for Speed 3DO and PC car extractor v0.1 (Vas.1987)     " + " PC file version ";
	} else

if (buffer == 0x4000000) { // 3DO file version
	flag3DO = true;
	Form1::Text = "Need for Speed 3DO and PC car extractor v0.1 (Vas.1987)     " + " 3DO file version ";
	}

	infile.read((char *)&buffer,sizeof(buffer));
	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[0]->Cells[0]->Value = "Filesize";
		dataGridView1->Rows[0]->Cells[1]->Value = length.ToString();
		dataGridView1->Rows->Add();
		dataGridView1->Rows[1]->Cells[0]->Value = "1st chunk offset";
		dataGridView1->Rows[1]->Cells[1]->Value = buffer.ToString();
		chunk1Offset = buffer;
	infile.read((char *)&buffer,sizeof(buffer));
	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[2]->Cells[0]->Value = "2nd chunk offset";
		dataGridView1->Rows[2]->Cells[1]->Value = buffer.ToString();
		chunk2Offset = buffer;
	infile.read((char *)&buffer,sizeof(buffer));
	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[3]->Cells[0]->Value = "3rd chunk offset";
		dataGridView1->Rows[3]->Cells[1]->Value = buffer.ToString();
		chunk3Offset = buffer;
	infile.read((char *)&buffer,sizeof(buffer));
	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[4]->Cells[0]->Value = "4th chunk offset";
		dataGridView1->Rows[4]->Cells[1]->Value = buffer.ToString();
		chunk4Offset = buffer;

		dataGridView1->Rows->Add();

	infile.read((char *)&buffer,sizeof(buffer));
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[6]->Cells[0]->Value = "Chunk 1 ORIP";
		if (buffer == 1346982479) {
			dataGridView1->Rows[6]->Cells[1]->Value = "true";
			} else {
		dataGridView1->Rows[6]->Cells[1]->Value = "false";
		}

	infile.read((char *)&buffer,sizeof(buffer));
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[7]->Cells[0]->Value = "Chunk 1 length";
		dataGridView1->Rows[7]->Cells[1]->Value = buffer.ToString();
		chunk1Length = buffer;


	infile.read((char *)&buffer,sizeof(buffer)); // Skip 2BCh (=700)
	infile.read((char *)&buffer,sizeof(buffer)); // Skip 0

	infile.read((char *)&buffer,sizeof(buffer)); // Block 8 size in 12-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[8]->Cells[0]->Value = "Block 8 size";
		dataGridView1->Rows[8]->Cells[1]->Value = buffer.ToString();
		size8 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Skip  ? the previous minus 10h
	infile.read((char *)&buffer,sizeof(buffer)); // Block 8 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[9]->Cells[0]->Value = "Block 8 offset in ORIP 1";
		dataGridView1->Rows[9]->Cells[1]->Value = buffer.ToString();
		off8 = buffer;	
	
	infile.read((char *)&buffer,sizeof(buffer)); // Block 2 size in 8-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[10]->Cells[0]->Value = "Block 2 size";
		dataGridView1->Rows[10]->Cells[1]->Value = buffer.ToString();
		size2 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Block 2 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[11]->Cells[0]->Value = "Block 2 offset in ORIP 1";
		dataGridView1->Rows[11]->Cells[1]->Value = buffer.ToString();
		off2 = buffer;		
	
	infile.read((char *)&buffer,sizeof(buffer)); // Block 1 size in 12-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[12]->Cells[0]->Value = "Block 1 size";
		dataGridView1->Rows[12]->Cells[1]->Value = buffer.ToString();
		size1 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Block 1 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[13]->Cells[0]->Value = "Block 1 offset in ORIP 1";
		dataGridView1->Rows[13]->Cells[1]->Value = buffer.ToString();
		off1 = buffer;	
	//label9->Text = "Filesize = " + length.ToString();

	infile.read((char *)&buffer,sizeof(buffer)); // Identifier string
	infile.read((char *)&buffer,sizeof(buffer)); // Identifier string
	infile.read((char *)&buffer,sizeof(buffer)); // Identifier string

	infile.read((char *)&buffer,sizeof(buffer)); // Block 3 size in 20-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[14]->Cells[0]->Value = "Block 3 size";
		dataGridView1->Rows[14]->Cells[1]->Value = buffer.ToString();
		size3 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Block 3 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[15]->Cells[0]->Value = "Block 3 offset in ORIP 1";
		dataGridView1->Rows[15]->Cells[1]->Value = buffer.ToString();
		off3 = buffer;	

	infile.read((char *)&buffer,sizeof(buffer)); // Block 4 size in 20-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[16]->Cells[0]->Value = "Block 4 size";
		dataGridView1->Rows[16]->Cells[1]->Value = buffer.ToString();
		size4 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Block 4 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[17]->Cells[0]->Value = "Block 4 offset in ORIP 1";
		dataGridView1->Rows[17]->Cells[1]->Value = buffer.ToString();
		off4 = buffer;

	infile.read((char *)&buffer,sizeof(buffer)); // Block 5 size in 28-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[18]->Cells[0]->Value = "Block 5 size";
		dataGridView1->Rows[18]->Cells[1]->Value = buffer.ToString();
		size5 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Block 5 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[19]->Cells[0]->Value = "Block 5 offset in ORIP 1";
		dataGridView1->Rows[19]->Cells[1]->Value = buffer.ToString();
		off5 = buffer;


	infile.read((char *)&buffer,sizeof(buffer)); // Block 9 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[20]->Cells[0]->Value = "Block 9 offset in ORIP 1";
		dataGridView1->Rows[20]->Cells[1]->Value = buffer.ToString();
		off9 = buffer;

	infile.read((char *)&buffer,sizeof(buffer)); // Block 6 size in 12-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[21]->Cells[0]->Value = "Block 6 size";
		dataGridView1->Rows[21]->Cells[1]->Value = buffer.ToString();
		size6 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Block 6 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[22]->Cells[0]->Value = "Block 6 offset in ORIP 1";
		dataGridView1->Rows[22]->Cells[1]->Value = buffer.ToString();
		off6 = buffer;

	infile.read((char *)&buffer,sizeof(buffer)); // Block 7 size in 12-byte records
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[23]->Cells[0]->Value = "Block 7 size";
		dataGridView1->Rows[23]->Cells[1]->Value = buffer.ToString();
		size7 = buffer;
	infile.read((char *)&buffer,sizeof(buffer)); // Block 7 offset in ORIP 1
//	if (flag3DO == true) {buffer = Swap4Bytes(buffer);}
		dataGridView1->Rows->Add();
		dataGridView1->Rows[24]->Cells[0]->Value = "Block 7 offset in ORIP 1";
		dataGridView1->Rows[24]->Cells[1]->Value = buffer.ToString();
		off7 = buffer;

	infile.read((char *)&buffer,sizeof(buffer)); // Skip 0
//		dataGridView1->Rows->Add();
//		dataGridView1->Rows[25]->Cells[0]->Value = "0";
//		dataGridView1->Rows[25]->Cells[1]->Value = buffer.ToString();
	infile.read((char *)&buffer,sizeof(buffer)); // Skip 0x70
//		dataGridView1->Rows->Add();
//		dataGridView1->Rows[26]->Cells[0]->Value = "0x70";
//		dataGridView1->Rows[26]->Cells[1]->Value = buffer.ToString();
	infile.read((char *)&buffer,sizeof(buffer)); // Skip 0
//		dataGridView1->Rows->Add();
//		dataGridView1->Rows[27]->Cells[0]->Value = "0";
//		dataGridView1->Rows[27]->Cells[1]->Value = buffer.ToString();
#endif;

infile.close();

// Savefilename
#if 1;
System::String^ outFilepath = System::IO::Path::GetDirectoryName(openFileDialog1->FileName) + "\\" + System::IO::Path::GetFileNameWithoutExtension(openFileDialog1->FileName) + ".obj";
label1->Text = outFilepath;
msclr::interop::marshal_context oMarshalContext1;
const char* filePath = oMarshalContext1.marshal_as<const char*>(outFilepath);

//outf = fopen(filePath,"w");

//fclose(outf);
#endif;

///////////////////////////////////////////////////////////////////////////////////////////
#if 0;
int temp, offset, offset2, offset2ORIP, tmp;
unsigned char tmp1;
const char triangle = 0x83;
const char quadrangle = 0x84;
const char quadOrNull = 0x8C;
unsigned int chunkLength = 0;
unsigned int offtoORIPabs = 0;
int offset2SHPIdir = 0;
float X, Y, Z = 0;
int counter = 0;
int vtcounter = 0;
int size13DObj=0;
int size83DObj=0;

// Read from the start of block 1
////////////////////////////////////////// Read block 1. There are size1 entries.
//#if 0;

FILE* inputfile;
fseek(inputfile, offtoORIPabs+off1, SEEK_SET); // Set to the start of 1st block

// Polygons count = size1:

// Prepare params for each polygon.
// Make dynamic array for the polys.
unsigned int *arrayPolyType = new unsigned int [size1];
int *arrayTextureN = new int [size1];
int *arrayPolyOff1 = new int [size1];
int *arrayPolyOff2 = new int [size1];

// Texture N
// Polygon1 offset
// Polygon2 offset
#if 1;
for (int i=0; i<size1; i++) {
	fread(&tmp1, 1, 1, inputfile); // Poly type
		arrayPolyType[i] = tmp1;
//		cout << "+arrayPolyType ["<< i << "]= 0x" << hex << arrayPolyType[i] << "\n";
	fread(&tmp1, 1, 1, inputfile); // Skip 1 byte
	fread(&tmp1, 1, 1, inputfile); // TextureN
		arrayTextureN[i] = tmp1;
//		cout << "+arrayTextureN ["<< i << "]= " << dec << arrayTextureN[i] << "\n";
	fread(&tmp1, 1, 1, inputfile); // Skip 1 byte
	fread(&temp, 4, 1, inputfile); // Poly1 offset
		arrayPolyOff1[i] = temp;
//		cout << "+arrayPolyOff1 ["<< i << "]= " << dec << arrayPolyOff1[i] << "\n";
	fread(&temp, 4, 1, inputfile); // Poly1 offset
		arrayPolyOff2[i] = temp;
//		cout << "+arrayPolyOff2 ["<< i << "]= " << dec << arrayPolyOff2[i] << "\n";
}
#endif; 


/////////////////////////////////////// Read block 2. There are size2 entries.
fseek(inputfile, offtoORIPabs+off2, SEEK_SET); // Set to the start of 2nd block
//cout << "off2 = 0x" << hex << offtoORIPabs+off2 << "\n";
//cout << "off2 = 0x" << hex << off2 << "\n";
//cout << "size2 = " << dec << size2 << "\n";

if (size2==0) {
	goto block3;
		} else {	

	}

unsigned int *arrayXcoord = new unsigned int [size2];
unsigned int *arrayYcoord = new unsigned int [size2];

#if 1;
for (int y=0; y<size2; y++) {
	fread(&temp, 4, 1, inputfile); // X coord
		arrayXcoord[y] = temp;
//		cout << "+arrayXcoord ["<< y << "]= " << dec << arrayXcoord[y] << "\n";
	fread(&temp, 4, 1, inputfile); // Y coord
		arrayYcoord[y] = temp;
//		cout << "+arrayYcoord ["<< y << "]= " << dec << arrayYcoord[y] << "\n";
}
#endif;

block3:

///////////////////////////////////// Read block 3. There are size3 entries.
fseek(inputfile, offtoORIPabs+off3, SEEK_SET); // Set to the start of 3rd block

int *arrayTexture = new int [size3];

#if 1;
for (int u=0; u<size3; u++) {
	fread(&temp, 4, 1, inputfile); // Skip 4 bytes.
	fread(&temp, 4, 1, inputfile); // Skip 4 bytes.
	fread(&temp, 4, 1, inputfile); // Identifier 2.
		// Store value of texture. We'll use it later in SHPI chunk.
		arrayTexture[u] = temp;
//		cout << "+arrayTexture ["<< u << "]= 0x" << hex << arrayTexture[u] << "\n";

	fread(&temp, 4, 1, inputfile); // Skip 4 bytes.
	fread(&temp, 4, 1, inputfile); // Skip 4 bytes.
}
#endif;

//////////////////////////////////////// Read block 4. There are size4 entries.
fseek(inputfile, offtoORIPabs+off4, SEEK_SET); // Set to the start of 4th block


if (size4==0) {
	goto block5;
		} else {	
	cout << "-------------------BLOCK 4 is nonZero!"<< endl;
	}


block5:
///////////////////////////////////// Read block 5. There are size5 entries.
fseek(inputfile, offtoORIPabs+off5, SEEK_SET); // Set to the start of 5th block

int *arrayPolyOffsetINBlock9 = new int [size5];
int *arrayNumOfVertices = new int [size5];
#if 1;
for (int p=0; p<size5; p++) {
		fread(&temp, 4, 1, inputfile); // Skip 4 bytes.	
		fread(&temp, 4, 1, inputfile); // Skip 4 bytes.	
		fread(&temp, 4, 1, inputfile); // Skip 4 bytes.	
		fread(&temp, 4, 1, inputfile); // Skip 4 bytes.	
		fread(&temp, 4, 1, inputfile); // Read polygon offset.
			arrayPolyOffsetINBlock9[p] = temp;
//					cout << "+arrayPolyOffsetINBlock9 ["<< p << "]= " << dec << arrayPolyOffsetINBlock9[p] << "\n";
		fread(&temp, 4, 1, inputfile); // Read number of vertices.
			arrayNumOfVertices[p] = temp;
//			cout << "+arrayNumOfVertices ["<< p << "]= " << dec << arrayNumOfVertices[p] << "\n";
		fread(&temp, 4, 1, inputfile); // Skip 4 bytes.
}
#endif;



//////////////////////////////////////// Read block 6. There are size6 entries.
fseek(inputfile, offtoORIPabs+off6, SEEK_SET); // Set to the start of 6th block

if (size6==0) {
	goto block7;
		} else {	
	cout << "-------------------BLOCK 6 is nonZero!"<< endl;
	}

block7:
/////////////////////////////////////// Read block 7. There are size7 entries.
fseek(inputfile, offtoORIPabs+off7, SEEK_SET); // Set to the start of 7th block

if (size7==0) {
	goto block8;
		} else {	
//	cout << "-------------------BLOCK 7 is nonZero!"<< endl;
	}

block8:
//////////////////////////////////// Read block 8. There are size8 entries.
fseek(inputfile, offtoORIPabs+off8, SEEK_SET); // Set to the start of 8th block

float *arrayX = new float [size8];
float *arrayZ = new float [size8];
float *arrayY = new float [size8];
#if 1;

for (int x=0; x<size8; x++) {
		fread(&temp, 4, 1, inputfile); // X coord.
			arrayX[x] = temp;
//			cout << "+arrayX ["<< x << "]= " << dec << arrayX[x] << "\n";
		fread(&temp, 4, 1, inputfile); // Z coord.
			arrayZ[x] = temp;
//			cout << "+arrayZ ["<< x << "]= " << dec << arrayZ[x] << "\n";
		fread(&temp, 4, 1, inputfile); // Y coord.
			arrayY[x] = -temp;
//			cout << "+arrayY ["<< x << "]= " << dec << arrayY[x] << "\n";
//			cout << "+arrayZ ["<< x << "]= " << dec << arrayZ[x] << "\n\n";
}

for (int a=0; a<size8; a++) {
	if ((arrayX[a]==0)&&(arrayY[a]==0)) continue;

/// Find new vector dir for current point.
// Tan alfa = Y/X. Alfa = arctg(Y/X).
//float alfa = 0;
//alfa = radiansToDegrees(atan(arrayY[a]/arrayX[a]));

//find_intersection2(Vector31(0, 0, (float)arrayZ[a]),													// Vector start
//				   Vector31(cos(degreesToRadians(alfa+angle)), sin(degreesToRadians(alfa+angle)), 0),	// Vector direction
//				   Vector31(0, 0, (float)arrayZ[a]),													// Sphere center
//				   sqrt((float)arrayX[a]*(float)arrayX[a]+(float)arrayY[a]*(float)arrayY[a]),			// Sphere radius
//				   r1, r2);																				// Result points

//(float)arrayX[a] = r2.x;
//(float)arrayY[a] = r2.y;
}

#endif;


///////////////////////////////////// Read block 9. There are size9 entries.
fseek(inputfile, offtoORIPabs+off9, SEEK_SET); // Set to the start of 9th block

// Read vertex numbers to SHPI. chunkLength - offtoORIPabs+off9
//cout << "Length of block 9 = 0x" << hex << chunkLength - off9 << "\n";
int length2 = 0;
length2 = chunkLength - off9;
size9 = length2/4;
//cout << "size9 = " << dec << size9 << "\n";

int *arrayVertexN = new int [size9];
#if 1;
for (int e=0; e<size9; e++) {
		fread(&temp, 4, 1, inputfile); // Read vertexN.
			arrayVertexN[e] = temp;
}
#endif;


//////////////////////////
// 1) Write vertexes from block 8 to the obj file.

//itoa(BitmapN, bmpname, 10);
//strcpy(tmpbmp, "Object3D.obj");


#if 1;

outf = fopen(filePath,"a");
fwrite("# 3D object\n",12,1,outf);
fprintf(outf, "mtllib Obj3D.mtl\n\n");
fprintf(outf, "o 3DObject%f\n", X);

// Write vertex coords.
for (int s=0; s<size8; s++) {
	fwrite("v ",2,1,outf); //1
	fprintf(outf, "%f ", (float)arrayX[s]/SCALE3D + (float)X);
	fprintf(outf, "%f ", (float)arrayZ[s]/SCALE3D + (float)Z);
	fprintf(outf, "%f ", (float)arrayY[s]/SCALE3D + (float)Y);
///	fprintf(outf, "%f ", (float)arrayX[s]);
///	fprintf(outf, "%f ", (float)arrayZ[s]);
///	fprintf(outf, "%f ", (float)arrayY[s]);
	fwrite("\n",1,1,outf);// New line
}
fwrite("\n",1,1,outf);// New line

// 2) pol1 polygons in block 1 points to block 9, and then translated in 3D in block 8.
// There are size1 polygons.

// Write vt params
fprintf(outf, "\n");

if (size2==0) {
	cout << "size2= " << dec << size2 << " Set vt params to defaults!\n";
		} else	
	{
	for (int a=0; a < size1; a++) {
		fwrite("vt ",3,1,outf);
		fprintf(outf, "%f %f\n", (float)arrayXcoord[arrayVertexN[arrayPolyOff2[a]]]/SCALE3DObjUVMap, 
			((float)arrayYcoord[arrayVertexN[arrayPolyOff2[a]]])/SCALE3DObjUVMap);

		fwrite("vt ",3,1,outf);
		fprintf(outf, "%f %f\n", (float)arrayXcoord[arrayVertexN[arrayPolyOff2[a]+1]]/SCALE3DObjUVMap, 
			((float)arrayYcoord[arrayVertexN[arrayPolyOff2[a]+1]])/SCALE3DObjUVMap);

		fwrite("vt ",3,1,outf);
		fprintf(outf, "%f %f\n", (float)arrayXcoord[arrayVertexN[arrayPolyOff2[a]+2]]/SCALE3DObjUVMap, 
			((float)arrayYcoord[arrayVertexN[arrayPolyOff2[a]+2]])/SCALE3DObjUVMap);

		fwrite("vt ",3,1,outf);
		fprintf(outf, "%f %f\n", (float)arrayXcoord[arrayVertexN[arrayPolyOff2[a]+3]]/SCALE3DObjUVMap, 
			(float)arrayYcoord[arrayVertexN[arrayPolyOff2[a]+3]]/SCALE3DObjUVMap);
		}
	}
//int vtcounter = 1;

// Write polygons
// N of polys based on previous max vertex counter.
// Vt params must be + size1*4, Size1 must be from previous object!
//vtExtend = size1*4; //=4 If it's quadrangle
#if 1;
if (size2==0)
{
	for (int b1=0; b1<size1; b1++) {// If block 2 == 0, set default vt params.

	fprintf(outf, "usemtl %d\n", arrayTextureN[b1]);
	fwrite("f ",2,1,outf);
	fprintf(outf, "%d %d %d %d\n", 
		arrayVertexN[arrayPolyOff1[b1]]+1 + counter,
		arrayVertexN[arrayPolyOff1[b1]+1]+1 + counter,
		arrayVertexN[arrayPolyOff1[b1]+2]+1 + counter,
		arrayVertexN[arrayPolyOff1[b1]+3]+1 + counter 
			);
	}

}

else
#endif;
{
	for (int b=0; b<size1; b++) {

	fprintf(outf, "usemtl %d\n", arrayTextureN[b]);
	fwrite("f ",2,1,outf);
	fprintf(outf, "%d/%d %d/%d %d/%d %d/%d\n", 
		arrayVertexN[arrayPolyOff1[b]]+1 + counter,
			vtcounter,
		arrayVertexN[arrayPolyOff1[b]+1]+1 + counter,
			vtcounter+1,
		arrayVertexN[arrayPolyOff1[b]+2]+1 + counter,
			vtcounter+2,
		arrayVertexN[arrayPolyOff1[b]+3]+1 + counter, 
			vtcounter+3);

	vtcounter += 4;
	}
}
fclose(outf);

// Make material file
///////////////////////////////////////////
FILE *mtlfile;
#if 1;
int c, count;


// Check for the unique materials.

// Open mtlfile for reading, check presence for all arrayTexture[] values.
//	mtlfile = fopen("Obj3D.mtl","r");

// Read all file and seek all arrayTexture[]. If found, this arrayTexture[] shouldn't be written to the mtlfile.
   ifstream file("Obj3D.mtl"); 
    string s;
	char find[256] = {0};
    char c1;
	bool found = false;

	 while (!file.eof()){ // Fill s string
        file.get(c1);
        s.push_back(c1);
    }
    file.close();


	for (int c=0; c < size3; c++) {


//		find = "892350512";
		strcpy(find,itoa(arrayTexture[c],find,10)); 
int pos;
		pos = s.find(find);
//		pos = s.find(itoa(arrayTexture[c],find,10));

	if (pos == -1)
		cout << "Material entry not found. Adding material to mtlfile." << endl;
	else {
		found = true;
//		cout << "Found! Position = " << pos << endl;
	}

	if (found == true) continue;///////////////////////// CHECK!!!!!!!!!!!!!!
		mtlfile = fopen("Obj3D.mtl","a");
		if (flag3DO == true) {	
			fprintf(mtlfile, "newmtl %d\n", c);
			fprintf(mtlfile, "map_Kd ObjectTextures3D3DO\\Tex%d.bmp\n", arrayTexture[c]);
//			cout << FamFileName3DO << endl;
/////			ExtractObject3D3DOTexture(BitmapN, FamFileName3DO, offset2SHPIdir, arrayTexture[c]);
			} else {
		
	if (found == true) continue;

		fprintf(mtlfile, "newmtl %d\n", c);
		fprintf(mtlfile, "map_Kd ObjectTextures3D\\Tex%d.bmp\n", arrayTexture[c]);
		// Extract object textures 
		offset2SHPIdir = offtoORIPabs+chunkLength;

/////		ExtractObject3DTexture(BitmapN, infilename, offset2SHPIdir, arrayTexture[c]);
		}
	fclose(mtlfile);
	found = false;
	}
#endif;

fclose(inputfile);
// Block 1
delete [] arrayPolyType;
delete [] arrayTextureN;
delete [] arrayPolyOff1;
delete [] arrayPolyOff2;

// Block 2
if ((!arrayXcoord)||(!arrayYcoord)) {
delete [] arrayXcoord;
delete [] arrayYcoord;
}

// Block 3
delete [] arrayTexture;

// Block 5
delete [] arrayPolyOffsetINBlock9;
delete [] arrayNumOfVertices;

// Block 8
delete [] arrayX;
delete [] arrayZ;
delete [] arrayY;

// Block 9
delete [] arrayVertexN;
size13DObj = size13DObj+size1;
size83DObj = size83DObj+size8;
#endif;

#endif; // outf open
///////////////////////////////////////////////////////////////////////////////////////////


//for (int i=0; i<28; i++) 
//	{
	
//	}


//infile.close();

		  }

			 }
};
}

