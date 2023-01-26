#pragma once
#include <iostream>
#include <string>
#define MAXN 512

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace Runtime::InteropServices;


	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ Sum;
	private: System::Windows::Forms::Button^ Difference;
	private: System::Windows::Forms::Button^ Multiplication;
	private: System::Windows::Forms::Button^ Division;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;




	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->Sum = (gcnew System::Windows::Forms::Button());
			this->Difference = (gcnew System::Windows::Forms::Button());
			this->Multiplication = (gcnew System::Windows::Forms::Button());
			this->Division = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 32);
			this->textBox1->MaxLength = 512;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(311, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(362, 32);
			this->textBox2->MaxLength = 512;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(304, 22);
			this->textBox2->TabIndex = 1;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(13, 161);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(653, 134);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// Sum
			// 
			this->Sum->Location = System::Drawing::Point(13, 91);
			this->Sum->Name = L"Sum";
			this->Sum->Size = System::Drawing::Size(133, 48);
			this->Sum->TabIndex = 3;
			this->Sum->Text = L"Sum";
			this->Sum->UseVisualStyleBackColor = true;
			this->Sum->Click += gcnew System::EventHandler(this, &MyForm::Sum_Click);
			// 
			// Difference
			// 
			this->Difference->Location = System::Drawing::Point(187, 91);
			this->Difference->Name = L"Difference";
			this->Difference->Size = System::Drawing::Size(136, 48);
			this->Difference->TabIndex = 4;
			this->Difference->Text = L"Difference";
			this->Difference->UseVisualStyleBackColor = true;
			this->Difference->Click += gcnew System::EventHandler(this, &MyForm::Difference_Click);
			// 
			// Multiplication
			// 
			this->Multiplication->Location = System::Drawing::Point(362, 91);
			this->Multiplication->Name = L"Multiplication";
			this->Multiplication->Size = System::Drawing::Size(133, 48);
			this->Multiplication->TabIndex = 5;
			this->Multiplication->Text = L"Multiplication";
			this->Multiplication->UseVisualStyleBackColor = true;
			this->Multiplication->Click += gcnew System::EventHandler(this, &MyForm::Multiplication_Click);
			// 
			// Division
			// 
			this->Division->Location = System::Drawing::Point(533, 89);
			this->Division->Name = L"Division";
			this->Division->Size = System::Drawing::Size(133, 50);
			this->Division->TabIndex = 6;
			this->Division->Text = L"Division";
			this->Division->UseVisualStyleBackColor = true;
			this->Division->Click += gcnew System::EventHandler(this, &MyForm::Division_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Enter first number:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(362, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(148, 17);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Enter second number:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 68);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(205, 17);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Choose an action with numbers";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 316);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Division);
			this->Controls->Add(this->Multiplication);
			this->Controls->Add(this->Difference);
			this->Controls->Add(this->Sum);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool big_arr(int a[], int b[], int len) {
			for (int i = 0; i < len; i++) {
				if (a[i] > b[i]) return true;
				else if (b[i] > a[i]) return false;
			}
		}
		void null_arr(int arr[], int len) {
			int i;
			for (i = 0; i < len; i++)
				arr[i] = 0;
		}
		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		private: System::Void Sum_Click(System::Object^ sender, System::EventArgs^ e) {
			int* Summ = new int[MAXN+1];
			String^ s = "";
			while (true) {
				richTextBox1->Clear();
				bool znak_first = false, znak_second = false;
				int len1 = 0, len2 = 0, len = 0;
				if (textBox1->TextLength == 0 || textBox1->TextLength == 1 && (textBox1->Text[0] == '-' || textBox1->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox2->TextLength == 0 || textBox2->TextLength == 1 && (textBox2->Text[0] == '-' || textBox2->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox1->Text[0] == '0' && textBox2->Text[0] == '0' || 
					((textBox1->Text[0] == '-' || textBox1->Text[0] == '+') && textBox1->Text[1] == '0' && textBox2->Text[0] == '0') || 
					((textBox2->Text[0] == '-' || textBox2->Text[0] == '+') && textBox2->Text[1] == '0' && textBox1->Text[0] == '0') ||
					((textBox1->Text[0] == '-' || textBox1->Text[0] == '+') && (textBox2->Text[0] == '-' || textBox2->Text[0] == '+') && textBox1->Text[1] == '0' && textBox2->Text[1] == '0')) {
					s = "0";
					break;
				}
				if (textBox1->Text[0] == '-') {
					znak_first = true; len1++;
				}
				else if (textBox1->Text[0] == '+') len1++;

				if (textBox2->Text[0] == '-') {
					znak_second = true; len2++;
				}
				else if (textBox2->Text[0] == '+') len2++;
				

				int* a = new int[MAXN];
				int* b = new int[MAXN];
				for (int i = 0; len1 < textBox1->TextLength; len1++, i++) {
					if (textBox1->Text[len1] >= 0x30 && textBox1->Text[len1] <= 0x39)
						a[i] = textBox1->Text[len1] - '0';
					else s = "Not stated";
				}
				if (s == "Not stated") break;
					
				for (int i = 0; len2 < textBox2->TextLength; len2++, i++) {
					if (textBox2->Text[len2] >= 0x30 && textBox2->Text[len2] <= 0x39)
						b[i] = textBox2->Text[len2] - '0';
					else s = "Not stated";
				}

				if (s == "Not stated") break;

				if (znak_first || textBox1->Text[0] == '+') len1--;
				if (znak_second || textBox2->Text[0] == '+') len2--;
				if (len1 == len2 && znak_second && !znak_first && big_arr(b, a, len1)) s += "-";
				if (len1 == len2 && !znak_second && znak_first && big_arr(a, b, len1)) s += "-";

				int len_new1 = len1, len_new2 = len2;

				if (len1 > len2) {
					while (len2 != len1) {
						for (int i = len2; i > 0; i--)
							b[i] = b[i - 1];
						b[0] = 0;
						len2++;
					}
				}
				else if (len2 > len1) {
					while (len1 != len2) {
						for (int i = len1; i > 0; i--)
							a[i] = a[i - 1];

						a[0] = 0;
						len1++;
					}
				}

				if ((znak_first && znak_second) || (!znak_first && !znak_second)) {
					len = len1 + 1;
					null_arr(Summ, len);
					for (int i = len1; i > 0; i--) {
						Summ[i] = (a[i - 1] + b[i - 1]) % 10;
						if ((a[i - 1] + b[i - 1]) > 9 && i > 1)
							a[i - 2] += 1;
					}
					if ((a[0] + b[0]) > 9) Summ[0] = (a[0] + b[0]) / 10;
					while (Summ[0] == 0) {
						for (int i = 0; i < len1; i++)
							Summ[i] = Summ[i + 1];
						len--;
					}
				}
				else if ((!znak_first && znak_second) || (znak_first && !znak_second)) {
					if (len_new2 > len_new1 || (len_new2 == len_new1) && big_arr(b, a, len1)) {
						for (int i = len1 - 1; i >= 0; i--) {
							if (a[i] > b[i] && i == 0) b[i] += 10;
							else if (a[i] > b[i]) {
								b[i] += 10; b[i - 1]--;
							}

							Summ[i] = b[i] - a[i];
							len++;
						}
					}
					else {
						for (int i = len1 - 1; i >= 0; i--) {
							if (b[i] > a[i] && i == 0) a[i] += 10;
							else if (b[i] > a[i]) {
								a[i] += 10; a[i - 1]--;
							}

							Summ[i] = a[i] - b[i];
							len++;
						}
					}

					while (Summ[0] == 0) {
						for (int i = 0; i < len1; i++)
							Summ[i] = Summ[i + 1];
						len--;
					}
				}

				if (len == 0) s += "0";
				else {
					if (znak_first && !znak_second && len_new1 > len_new2
						|| !znak_first && znak_second && len_new1 < len_new2 
						|| znak_first && znak_second) s += "-";
					for (int i = 0; i < len; i++)
						s += (char)Summ[i];
				}
				delete[] a;
				delete[] b;
				delete[] Summ;
				break;
			}
			richTextBox1->AppendText(s);
		}
		private: System::Void Difference_Click(System::Object^ sender, System::EventArgs^ e) {
			int* Summ = new int[MAXN + 1];
			String^ s = "";
			while (true) {
				richTextBox1->Clear();
				bool znak_first = false, znak_second = false;
				int len1 = 0, len2 = 0, len = 0;
				if (textBox1->TextLength == 0 || textBox1->TextLength == 1 && (textBox1->Text[0] == '-' || textBox1->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox2->TextLength == 0 || textBox2->TextLength == 1 && (textBox2->Text[0] == '-' || textBox2->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox1->Text[0] == '0' && textBox2->Text[0] == '0' ||
					((textBox1->Text[0] == '-' || textBox1->Text[0] == '+') && textBox1->Text[1] == '0' && textBox2->Text[0] == '0') ||
					((textBox2->Text[0] == '-' || textBox2->Text[0] == '+') && textBox2->Text[1] == '0' && textBox1->Text[0] == '0') ||
					((textBox1->Text[0] == '-' || textBox1->Text[0] == '+') && (textBox2->Text[0] == '-' || textBox2->Text[0] == '+') && textBox1->Text[1] == '0' && textBox2->Text[1] == '0')) {
					s = "0";
					break;
				}
				if (textBox1->Text[0] == '-') {
					znak_first = true; len1++;
				}
				else if (textBox1->Text[0] == '+') len1++;

				if (textBox2->Text[0] == '-') {
					znak_second = true; len2++;
				}
				else if (textBox2->Text[0] == '+') len2++;


				int* a = new int[MAXN];
				int* b = new int[MAXN];
				for (int i = 0; len1 < textBox1->TextLength; len1++, i++) {
					if (textBox1->Text[len1] >= 0x30 && textBox1->Text[len1] <= 0x39)
						a[i] = textBox1->Text[len1] - '0';
					else s = "Not stated";
				}
				if (s == "Not stated") break;

				for (int i = 0; len2 < textBox2->TextLength; len2++, i++) {
					if (textBox2->Text[len2] >= 0x30 && textBox2->Text[len2] <= 0x39)
						b[i] = textBox2->Text[len2] - '0';
					else s = "Not stated";
				}

				if (s == "Not stated") break;

				if (znak_first || textBox1->Text[0] == '+') len1--;
				if (znak_second || textBox2->Text[0] == '+') len2--;

				int len_new1 = len1, len_new2 = len2;

				if (len1 > len2) {
					while (len2 != len1) {
						for (int i = len2; i > 0; i--)
							b[i] = b[i - 1];
						b[0] = 0;
						len2++;
					}
				}
				else if (len2 > len1) {
					while (len1 != len2) {
						for (int i = len1; i > 0; i--)
							a[i] = a[i - 1];

						a[0] = 0;
						len1++;
					}
				}
				if (znak_first && znak_second && big_arr(a, b, len1)) s += "-";
				if (!znak_first && !znak_second && big_arr(b, a, len1)) s += "-";
				if (znak_first && !znak_second) s += "-";

				if ((!znak_first && znak_second) || (znak_first && !znak_second)) {
					len = len1 + 1;
					null_arr(Summ, len);
					for (int i = len1; i > 0; i--) {
						Summ[i] = (a[i - 1] + b[i - 1]) % 10;
						if ((a[i - 1] + b[i - 1]) > 9 && i > 1)
							a[i - 2] += 1;
					}
					if ((a[0] + b[0]) > 9) Summ[0] = (a[0] + b[0]) / 10;
					while (Summ[0] == 0) {
						for (int i = 0; i < len1; i++)
							Summ[i] = Summ[i + 1];
						len--;
					}
				}
				else if ((!znak_first && !znak_second) || (znak_first && znak_second)) {
					if (len_new2 > len_new1 || (len_new2 == len_new1) && big_arr(b, a, len1)) {
						for (int i = len1 - 1; i >= 0; i--) {
							if (a[i] > b[i] && i == 0) b[i] += 10;
							else if (a[i] > b[i]) {
								b[i] += 10; b[i - 1]--;
							}

							Summ[i] = b[i] - a[i];
							len++;
						}
					}
					else {
						for (int i = len1 - 1; i >= 0; i--) {
							if (b[i] > a[i] && i == 0) a[i] += 10;
							else if (b[i] > a[i]) {
								a[i] += 10; a[i - 1]--;
							}

							Summ[i] = a[i] - b[i];
							len++;
						}
					}

					while (Summ[0] == 0) {
						for (int i = 0; i < len1; i++)
							Summ[i] = Summ[i + 1];
						len--;
					}
				}

				if (len == 0) s += "0";
				else {
					for (int i = 0; i < len; i++)
						s += (char)Summ[i];
				}
				delete[] a;
				delete[] b;
				delete[] Summ;
				break;
			}
			richTextBox1->AppendText(s);
		}
		private: System::Void Multiplication_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ s = "";
			while (true) {
				richTextBox1->Clear();
				int len1 = 0, len2 = 0;
				bool znak_first = false, znak_second = false;
				if (textBox1->TextLength == 0 || textBox2->TextLength == 0) {
					s = "Not stated";
					break;
				}
				if (textBox1->TextLength == 1 && (textBox1->Text[0] == '-' || textBox1->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox2->TextLength == 1 && (textBox2->Text[0] == '-' || textBox2->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox1->Text[0] == '0' && textBox2->Text[0] == '0' ||
					((textBox1->Text[0] == '-' || textBox1->Text[0] == '+') && textBox1->Text[1] == '0' && textBox2->Text[0] == '0') ||
					((textBox2->Text[0] == '-' || textBox2->Text[0] == '+') && textBox2->Text[1] == '0' && textBox1->Text[0] == '0') ||
					((textBox1->Text[0] == '-' || textBox1->Text[0] == '+') && (textBox2->Text[0] == '-' || textBox2->Text[0] == '+') && textBox1->Text[1] == '0' && textBox2->Text[1] == '0')) {
					s = "0";
					break;
				}
				if (textBox1->Text[0] == '-') {
					len1++; znak_first = true;
				}
				if (textBox1->Text[0] == '+') len1++;
				if (textBox2->Text[0] == '-') {
					len2++; znak_second = true;
				}
				if (textBox2->Text[0] == '+') len2++;

				int* a = new int[MAXN];
				int* b = new int[MAXN];
				for (int i = 0; len1 < textBox1->TextLength; len1++, i++) {
					if (textBox1->Text[len1] >= 0x30 && textBox1->Text[len1] <= 0x39)
						a[i] = textBox1->Text[len1] - '0';
					else s = "Not stated";
				}
				if (s == "Not stated") break;

				for (int i = 0; len2 < textBox2->TextLength; len2++, i++) {
					if (textBox2->Text[len2] >= 0x30 && textBox2->Text[len2] <= 0x39)
						b[i] = textBox2->Text[len2] - '0';
					else s = "Not stated";
				}
				if (s == "Not stated") break;

				if (znak_first || textBox1->Text[0] == '+') len1--;
				if (znak_second || textBox2->Text[0] == '+') len2--;

				int len = len1 + len2;
				int* Summ = new int[len];

				int* p_otvet = new int[len];

				null_arr(Summ, len);
				null_arr(p_otvet, len);

				int i, j;
				int flag;
				for (flag = 1; flag <= len2; flag++) {
					for (i = 0; i < len1; i++) p_otvet[i + flag] = a[i];


					for (i = 0; i < b[flag - 1]; i++) {
						for (j = len - 1; j >= 0; j--) {
							Summ[j] += p_otvet[j];
							if (Summ[j] >= 10) {
								Summ[j] -= 10;
								Summ[j - 1]++;
							}
						}
					}

					null_arr(p_otvet, len);
				}
				if (Summ[0] == 0) {
					i = 0;
					for (i = 0; i < len - 1; i++)
						Summ[i] = Summ[i + 1];
					len--;
				}
				if (len == 0) s += "0";
				else {
					if ((!znak_first && znak_second) || (znak_first && !znak_second)) s += "-";
					for (int i = 0; i < len; i++)
						s += (char)Summ[i];
				}
				delete[] a;
				delete[] b;
				delete[] p_otvet;
				delete[] Summ;
				break;
			}
			richTextBox1->AppendText(s);
		}
		private: System::Void Division_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ s = "";
			while (true) {
				richTextBox1->Clear();
				int len1 = 0, len2 = 0;
				bool znak_first = false, znak_second = false;
				if (textBox1->TextLength == 0 || textBox2->TextLength == 0) {
					s = "Not stated";
					break;
				}
				if (textBox1->TextLength == 1 && (textBox1->Text[0] == '-' || textBox1->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox2->TextLength == 1 && (textBox2->Text[0] == '-' || textBox2->Text[0] == '+')) {
					s = "Not stated";
					break;
				}
				if (textBox2->Text == "0" || ((textBox2->Text[0] == '-' || textBox2->Text[0] == '+') && textBox2->Text[1] == '0')) {
					s = "Not stated";
					break;
				}
				if (textBox1->Text == "0" || ((textBox1->Text[0] == '-' || textBox1->Text[0] == '+') && textBox1->Text[1] == '0')) {
					s = "0";
					break;
				}
				if (textBox1->Text[0] == '-') {
					len1++; znak_first = true;
				}
				if (textBox1->Text[0] == '+') len1++;
				if (textBox2->Text[0] == '-') {
					len2++; znak_second = true;
				}
				if (textBox2->Text[0] == '+') len2++;

				int* a = new int[MAXN];
				int* b = new int[MAXN];
				for (int i = 0; len1 < textBox1->TextLength; len1++, i++) {
					if (textBox1->Text[len1] >= 0x30 && textBox1->Text[len1] <= 0x39)
						a[i] = textBox1->Text[len1] - '0';
					else s = "Not stated";
				}
				if (s == "Not stated") break;

				for (int i = 0; len2 < textBox2->TextLength; len2++, i++) {
					if (textBox2->Text[len2] >= 0x30 && textBox2->Text[len2] <= 0x39)
						b[i] = textBox2->Text[len2] - '0';
					else s = "Not stated";
				}
				if (s == "Not stated") break;

				if (znak_first || textBox1->Text[0] == '+') len1--;
				if (znak_second || textBox2->Text[0] == '+') len2--;

				if (len1 == len2 && big_arr(b, a, len1) || len1 < len2 ) {
					s = "Not stated";
					break;
				}
				if (len1 == len2) {
					int i = 0, j = 0;

					bool arr = true;
					for (; j < len2; i++, j++) {
						if (a[i] != b[j]) arr = false;
					}
					if (arr) {
						if ((znak_first || znak_second) && !(znak_first && znak_second)) s = "-1";
						else s = "1";
						break;
					}
				}

				int len = len1 - len2 + 1;
				int* Summ = new int[len];

				int* p_otvet = new int[len1];

				null_arr(Summ, len);
				null_arr(p_otvet, len1);

				int flag, i, j, number = 0;
				for (flag = 0; flag < len; flag++) {
					for (i = 0; i < len2; i++) p_otvet[i + flag] = b[i];

					bool temp = false;
					while (true) {
						int t = 0;
						for (j = 0; j < len1; ) {
							if (a[j] < p_otvet[j]) { temp = true;  break; }
							else if (a[j] == p_otvet[j]) j++;
							else break;
						}

						if (flag == len - 1 && temp) {
							for (i = 0; i < len1; i++)
								if (a[i] == 0) t++;
							if (t != len1) {
								s = "Not stated";
								break;
							}
						}

						else if (temp) {
							for (i = 0; i < len - 1; i++) Summ[i] = Summ[i + 1];
							Summ[len - 1] = number;
							number = 0;
							temp = false;
							break;
						}

						t = 0;
						for (i = 0; i < len1; i++) {
							if (a[i] == 0) t++;
						}
						if (t == len1) {
							for (i = 0; i < len - 1; i++) Summ[i] = Summ[i + 1];
							Summ[len - 1] = number;
							number = 0;
							break;
						}

						for (j = len1 - 1; j >= 0; j--) {
							a[j] -= p_otvet[j];
							if (a[j] < 0) {
								a[j] += 10;
								a[j - 1]--;
							}
						}
						number++;
					}
					if (s == "Not stated") break;
					null_arr(p_otvet, len1);
				}
				if (s == "Not stated") break;

				if (Summ[0] == 0) {
					i = 0;
					for (i = 0; i < len - 1; i++)
						Summ[i] = Summ[i + 1];
					len--;
				}
				if (len == 0) s += "0";
				else {
					if ((!znak_first && znak_second) || (znak_first && !znak_second)) s += "-";
					for (int i = 0; i < len; i++)
						s += (char)Summ[i];
				}

				delete[] a;
				delete[] b;
				delete[] p_otvet;
				delete[] Summ;
				break;
			}
			richTextBox1->AppendText(s);
		}
	};
}
