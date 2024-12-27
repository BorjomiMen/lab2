#pragma once
#include "NamesOfFunctions.h"
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace std;
namespace LabNumeric2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	double left_boarder = 0, right_boarder = 1;
	double h;
	int n;
	double breaking_point = 0.25, mu1 = 0, mu2 = 1;
	vector<vector<double>> result;
	int is_test_task = 0;
	double maxDiffX, maxDifference;
	vector<int> ns;
	string str;
	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Тестовая задача", L"Основная задача" });
			this->comboBox1->Location = System::Drawing::Point(437, 10);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(237, 30);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->Text = L" Задача";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(26, 13);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 22);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Количество узлов";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->textBox1->Location = System::Drawing::Point(289, 10);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(144, 30);
			this->textBox1->TabIndex = 2;
			this->textBox1->Visible = false;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::Orange;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->GridColor = System::Drawing::Color::Beige;
			this->dataGridView1->Location = System::Drawing::Point(897, 137);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(742, 524);
			this->dataGridView1->TabIndex = 3;
			this->dataGridView1->Visible = false;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(435, 64);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(290, 49);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Заполнить таблицу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->label2->Location = System::Drawing::Point(8, 669);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 22);
			this->label2->TabIndex = 5;
			this->label2->Text = L"   ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(729, 64);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(366, 49);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Проверка сходимости";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			this->textBox2->Location = System::Drawing::Point(12, 55);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(353, 30);
			this->textBox2->TabIndex = 7;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_Leave);
			this->textBox2->Leave += gcnew System::EventHandler(this, &MyForm::textBox2_Leave);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(1036, 10);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(78, 49);
			this->button3->TabIndex = 8;
			this->button3->Text = L"=";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(562, 137);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(310, 49);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Таблица";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::Orange;
			this->dataGridView2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView2->GridColor = System::Drawing::Color::Beige;
			this->dataGridView2->Location = System::Drawing::Point(12, 202);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 82;
			this->dataGridView2->RowTemplate->Height = 33;
			this->dataGridView2->Size = System::Drawing::Size(802, 541);
			this->dataGridView2->TabIndex = 10;
			this->dataGridView2->Visible = false;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Аналит. и числ. решения", L"Разность аналит. и числ. решения" });
			this->comboBox2->Location = System::Drawing::Point(708, 27);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(305, 30);
			this->comboBox2->TabIndex = 11;
			this->comboBox2->Text = L"Графики";
			this->comboBox2->Visible = false;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(11, 124);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(689, 567);
			this->chart1->TabIndex = 12;
			this->chart1->Text = L"chart1";
			this->chart1->Visible = false;
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Числ.  решение", L"Разница двух численных решений" });
			this->comboBox3->Location = System::Drawing::Point(728, 20);
			this->comboBox3->Margin = System::Windows::Forms::Padding(2);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(304, 30);
			this->comboBox3->TabIndex = 13;
			this->comboBox3->Text = L"Графики:";
			this->comboBox3->Visible = false;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Beige;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1728, 860);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void Algoritm10(string str, int& k, string* W)
		{
			string zn = ",!?:;.";
			k = 0;
			str += " ";
			for (int i = 0; i < str.length(); i++) {
				int l = zn.find(str[i]);
				if (l >= 0 && l < zn.length()) {
					if (W[k].length() > 0) {
						k++;
					}
					W[k] = str[i];
				}
				else {
					if (str[i] == ' ') {
						if (W[k].length() > 0) {
							W[++k] = "";
						}
					}
					else {
						W[k] = W[k] + str[i];
					}
				}
			}
		}
#pragma endregion
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	is_test_task = comboBox1->SelectedIndex;
	if (is_test_task == 0) {
		label1->Visible = true;
		textBox1->Visible = true;
		textBox1->Text = "";
		textBox2->Text = "";
		comboBox2->Visible = false;
		comboBox3->Visible = false;
		chart1->Visible = false;
		textBox2->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
		button4->Visible = false;
		dataGridView1->Visible = false;
		dataGridView2->Visible = false;
		this->label1->Text = "Количество разбиений:";
	}
	else {
		label1->Visible = true;
		textBox1->Visible = true;
		textBox2->Visible = false;
		textBox1->Text = "";
		textBox2->Text = "";
		comboBox2->Visible = false;
		comboBox3->Visible = false;
		chart1->Visible = false;
		button2->Visible = false;
		button3->Visible = false;
		button4->Visible = false;
		dataGridView1->Visible = false;
		dataGridView2->Visible = false;
		this->label1->Text = "Количество разбиений:";
	}
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	try {
		int n = Int32::Parse(textBox1->Text);
		int step = 1;
		if (n > 9999) {
			step = 100;
		}
		else if (n > 1999) {
			step = 50;
		}
		else if (n > 999) {
			step = 10;
		}
		else if (n > 499) {
			step = 5;
		}
		else if (n > 299) {
			step = 3;
		}
		int rows = n/step;
		int columns = 5;
		dataGridView1->Visible = true;
		button1->Visible = true;
		label2->Visible = true;
		// Очищаем текущую таблицу
		dataGridView1->Rows->Clear();
		dataGridView1->Columns->Clear();
		if(is_test_task==0){
			dataGridView1->Columns->Add("Column0", "i");
			dataGridView1->Columns->Add("Column1", "xi");
			dataGridView1->Columns->Add("Column2", "vi");
			dataGridView1->Columns->Add("Column3", "ui");
			dataGridView1->Columns->Add("Column4", "vi-ui");
		}
		else
		{
			dataGridView1->Columns->Add("Column0", "i");
			dataGridView1->Columns->Add("Column1", "xi");
			dataGridView1->Columns->Add("Column2", "vi");
			dataGridView1->Columns->Add("Column3", "v2i");
			dataGridView1->Columns->Add("Column4", "vi-v2i");
		}
		dataGridView1->Rows->Add(rows);
	}
	catch (FormatException^) {
		if (String::IsNullOrWhiteSpace(textBox1->Text)) {
			dataGridView1->Visible = false;
			button1->Visible = false;
			chart1->Visible = false;
			// Очистка и настройка графика
			chart1->Series->Clear();
			chart1->ChartAreas->Clear();
			this->label2->Text = " ";
			return;
		}
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	button2->Visible = true;
	ns.clear();
	n = Int32::Parse(textBox1->Text);
	h = 1. / n;
	// Определяем шаг вывода в таблицу
	int step = 1;
	if (n > 9999) {
		step = 100;
	}
	else if (n > 99999) {
		step = 1000;
	}
	else if (n > 999) {
		step = 10;
	}
	else if (n > 499) {
		step = 5;
	}
	else if (n > 299) {
		step = 3;
	}
	result = differenceScheme(n, mu1, mu2, breaking_point, (1 - is_test_task), &maxDifference, &maxDiffX);
	int j= 0;
	for (int i = 0; i <= n/step; i++) {
		dataGridView1->Rows[i]->Cells[0]->Value = j;
		dataGridView1->Rows[i]->Cells[1]->Value = result[j][0];
		dataGridView1->Rows[i]->Cells[2]->Value = result[j][1];
		dataGridView1->Rows[i]->Cells[3]->Value = result[j][2];
		dataGridView1->Rows[i]->Cells[4]->Value = result[j][3];
		//ns.push_back(j);
		j+= step;
	}
	if (is_test_task == 0)
	{
		this->label2->Text = L"n = «"+ n +"»;\nepsilon = 0.5*10 –6;\nepsilon1 = «" + maxDifference +"»;\ x = «"+ maxDiffX +"»";
		comboBox2->Visible = true;
	}
	else
	{
		this->label2->Text = L" n = «" + n + "»;\nepsilon = 0.5*10 –6;\nepsilon2 = «" + maxDifference + "»;\n x = «" + maxDiffX + "»";
		comboBox3->Visible = true;
	}
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int is_number_gr = comboBox2->SelectedIndex;
	if (is_number_gr == 0)
	{
		n = Int32::Parse(textBox1->Text);
		result = differenceScheme(n, mu1, mu2, breaking_point, (1 - is_test_task), &maxDifference, &maxDiffX); 
		chart1->Series->Clear();
		chart1->ChartAreas->Clear();
		chart1->ChartAreas->Add("Default");
		chart1->ChartAreas["Default"]->AxisX->Title = "x";
		chart1->ChartAreas["Default"]->AxisY->Title = "u(x), v(x)";
		chart1->Series->Add("Аналитическое решение u(x)");
		chart1->Series["Аналитическое решение u(x)"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
		chart1->Series["Аналитическое решение u(x)"]->BorderWidth = 4;
		chart1->Series["Аналитическое решение u(x)"]->Color = System::Drawing::Color::Blue;
		chart1->Series->Add("Численное решение v(x)");
		chart1->Series["Численное решение v(x)"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
		chart1->Series["Численное решение v(x)"]->BorderWidth = 2;
		chart1->Series["Численное решение v(x)"]->Color = System::Drawing::Color::Red;
		for (int i = 0; i < result.size(); i++) {
			double x = result[i][0];
			double u_x = result[i][2]; // Истинное решение
			double v_x = result[i][1]; // Численное решение
			chart1->Series["Аналитическое решение u(x)"]->Points->AddXY(x, u_x); // Добавляем точки в аналитическое решение
			chart1->Series["Численное решение v(x)"]->Points->AddXY(x, v_x);    // Добавляем точки в численное решение
		}
		chart1->Visible = true;
	}
	else
	{
		n = Int32::Parse(textBox1->Text);
		result = differenceScheme(n, mu1, mu2, breaking_point, (1 - is_test_task), &maxDifference, &maxDiffX);
		chart1->Series->Clear();
		chart1->ChartAreas->Clear();
		chart1->ChartAreas->Add("Default");
		chart1->ChartAreas["Default"]->AxisX->Title = "x";
		chart1->ChartAreas["Default"]->AxisY->Title = "u(x)-v(x)";
		chart1->Series->Add("u(x)-v(x)");
		chart1->Series["u(x)-v(x)"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
		chart1->Series["u(x)-v(x)"]->BorderWidth = 2;
		chart1->Series["u(x)-v(x)"]->Color = System::Drawing::Color::Blue;
		for (int i = 0; i < result.size(); i++) {
			double x = result[i][0];
			double u_x = result[i][2]; // Истинное решение
			double v_x = result[i][1];// Численное решение
			double vu = u_x - v_x;
			chart1->Series["u(x)-v(x)"]->Points->AddXY(x, vu); // Добавляем точки в решение
		}
		chart1->Visible = true;
	}
}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int is_number_gr = comboBox3->SelectedIndex;
	if (is_number_gr == 0)
	{
		n = Int32::Parse(textBox1->Text);
		result = differenceScheme(n, mu1, mu2, breaking_point, (1 - is_test_task), &maxDifference, &maxDiffX);
		chart1->Series->Clear();
		chart1->ChartAreas->Clear();
		chart1->ChartAreas->Add("Default");
		chart1->ChartAreas["Default"]->AxisX->Title = "x";
		chart1->ChartAreas["Default"]->AxisY->Title = "v(x), v2(x)";
		chart1->Series->Add("Численное решение v(x)");
		chart1->Series["Численное решение v(x)"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
		chart1->Series["Численное решение v(x)"]->BorderWidth = 4;
		chart1->Series["Численное решение v(x)"]->Color = System::Drawing::Color::Blue;
		chart1->Series->Add("Численное решение v2(x)");
		chart1->Series["Численное решение v2(x)"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
		chart1->Series["Численное решение v2(x)"]->BorderWidth = 2;
		chart1->Series["Численное решение v2(x)"]->Color = System::Drawing::Color::Red;
		for (int i = 0; i < result.size(); i++) {
			double x = result[i][0];
			double v2_x = result[i][2]; // Численное решение с половинным шагом
			double v_x = result[i][1]; // Численное решение
			chart1->Series["Численное решение v(x)"]->Points->AddXY(x, v_x); // Добавляем точки в численное решение с половинным шагом
			chart1->Series["Численное решение v2(x)"]->Points->AddXY(x, v2_x);    // Добавляем точки в численное решение
		}
		chart1->Visible = true;
	}
	else
	{
		n = Int32::Parse(textBox1->Text);
		result = differenceScheme(n, mu1, mu2, breaking_point, (1 - is_test_task), &maxDifference, &maxDiffX);
		// Очистка и настройка графика
		chart1->Series->Clear();
		chart1->ChartAreas->Clear();
		chart1->ChartAreas->Add("Default");
		chart1->ChartAreas["Default"]->AxisX->Title = "x";
		chart1->ChartAreas["Default"]->AxisY->Title = "v(x)-v2(x)";
		chart1->Series->Add("v(x)-v2(x)");
		chart1->Series["v(x)-v2(x)"]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
		chart1->Series["v(x)-v2(x)"]->BorderWidth = 2;
		chart1->Series["v(x)-v2(x)"]->Color = System::Drawing::Color::Blue;
		for (int i = 0; i < result.size(); i++) {
			double x = result[i][0];
			double v2_x = result[i][2];
			double v_x = result[i][1];
			double vv = v_x - v2_x;
			chart1->Series["v(x)-v2(x)"]->Points->AddXY(x, vv);
		}
		chart1->Visible = true;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	label2->Visible = false;
	// Очищаем текущую таблицу
	dataGridView1->Rows->Clear();
	dataGridView1->Columns->Clear();
	if (is_test_task == 0) {
		dataGridView1->Columns->Add("Column0", "n");
		dataGridView1->Columns->Add("Column1", "max|vi-ui|");
		dataGridView1->Columns->Add("Column2", "e1i-1/e1i");
	}
	else
	{
		dataGridView1->Columns->Add("Column0", "n");
		dataGridView1->Columns->Add("Column1", "max|vi-v2i|");
		dataGridView1->Columns->Add("Column2", "e2i-1/e2i");
	}
	dataGridView1->Visible = true;
	this->label1->Text = "Дай 5  n(так надо):";
	textBox1->Visible = false;
	comboBox2->Visible = false;
	comboBox3->Visible = false;
	chart1->Visible = false;
	button1->Visible = false;
	textBox2->Visible = true;
}
private: System::Void textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
	// Получаем строку из textBox2
	str = msclr::interop::marshal_as<string>(textBox2->Text);
	button3->Visible = true;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	// Очищаем текущую таблицу
	dataGridView1->Rows->Clear();
	ns.clear();
	int n = str.length();
	if (n > 0) {
		string* W = new string[n + 2];
		int k = 5;
		Algoritm10(str, k, W);
		for (int i = 0; i < k; i++) {
			ns.push_back(atoi(W[i].c_str()));  // Преобразуем строку в число и добавляем в вектор
		}
		delete[] W;
	}
	double previousEps = 1;
	int rows = 4;
	dataGridView1->Rows->Add(rows);
	for (int i = 0; i < 5; i++) {
		double maxDiffXX, maxDifference;
		result = differenceScheme(ns[i], mu1, mu2, breaking_point, (1-is_test_task), &maxDifference, &maxDiffX);
		dataGridView1->Rows[i]->Cells[0]->Value = ns[i];
		dataGridView1->Rows[i]->Cells[1]->Value = maxDifference;
		if (!i) {
			dataGridView1->Rows[i]->Cells[2]->Value = 0;
		}
		else {
			dataGridView1->Rows[i]->Cells[2]->Value = previousEps / maxDifference;
		}	
		previousEps = maxDifference;
	}
	button2->Visible = false;
	button4->Visible = true;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView2->Columns->Add("Column0", "n");
	dataGridView2->Columns->Add("Column1", "max|vi-ui|");
	dataGridView2->Columns->Add("Column2", "max|vi-v2i|");
	dataGridView2->Columns->Add("Column3", "lg(n)");
	dataGridView2->Columns->Add("Column4", "-lg(e1)");
	dataGridView2->Columns->Add("Column5", "-lg(e2)");
	int rows = 20;
	dataGridView2->Rows->Add(rows);
	ns = { 10,20,50,80,100,200,500,800,1000,2000,5000,8000,10000,20000,50000,80000,100000,200000,500000,800000,1000000 };//если изменяем кол-во чисел нужноизменить кол-во строк
	for (int i = 0; i < size(ns); i++) {
		double maxDiffXTest, maxDifferenceTest;
		double maxDiffXMain, maxDifferenceMain;
		vector<vector<double>>resultTest = differenceScheme(ns[i], mu1, mu2, breaking_point, 1, &maxDifferenceTest, &maxDiffXTest);
		vector<vector<double>>resultMain = differenceScheme(ns[i], mu1, mu2, breaking_point, 0, &maxDifferenceMain, &maxDiffXMain);
		dataGridView2->Rows[i]->Cells[0]->Value = ns[i];
		dataGridView2->Rows[i]->Cells[1]->Value = maxDifferenceTest;
		dataGridView2->Rows[i]->Cells[2]->Value = maxDifferenceMain;
		dataGridView2->Rows[i]->Cells[3]->Value = log10(ns[i]);
		dataGridView2->Rows[i]->Cells[4]->Value = -log10(maxDifferenceTest);
		dataGridView2->Rows[i]->Cells[5]->Value = -log10(maxDifferenceMain);
	}
	dataGridView2->Visible = true;
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
