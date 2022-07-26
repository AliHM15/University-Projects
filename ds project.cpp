#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include<sstream>

using namespace std;

class Node {
public:
    string n;
    string p;
    string k;
    string temperature;
    string humidity;
    string ph;
    string rainfall;
    string label;
    Node* next;

    Node()
    {
        n = "";
        p = "";
        k = "";
        temperature = "";
        humidity = "";
        ph = "";
        rainfall = "";
        label = "";
        next = NULL;
    }
    Node(string n, string p, string k, string temperature, string humidity, string ph, string rainfall, string label)
    {
        this->n = n;
        this->p = p;
        this->k = k;
        this->temperature = temperature;
        this->humidity = humidity;
        this->ph = ph;
        this->rainfall = rainfall;
        this->label = label;
        next = NULL;
    }
};

class node2
{
public:

    string area_c;
    string area;
    string item_c;
    string item;
    string element_c;
    string element;
    string year_c;
    string year;
    string unit;
    string value;
    string flag;
    node2* next;
    node2()
    {
        area_c = "";
        area = "";
        item_c = "";
        item = "";
        element_c = "";
        element = "";
        year_c = "";
        year = "";
        unit = "";
        value = "";
        flag = "";
        next = NULL;


    }

    node2(string area_c, string area, string item_c, string item, string element_c, string element, string year_c, string year, string unit, int value, string flag)
    {
        this->area_c = area_c;
        this->area = area;
        this->item_c = item_c;
        this->item = item_c;
        this->element_c = element_c;
        this->element = element;
        this->year_c = year_c;
        this->year = year;
        this->unit = unit;
        this->value = value;
        this->flag = flag;
        //right=NULL;
        next = NULL;


    }

};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        head = NULL;
    }
    SinglyLinkedList(Node* n) {
        head = n;
    }


    // 2. Append a node to the list
    void appendNode(Node* n)
    {

        if (head == NULL) {
            head = n;
        }
        else {
            Node* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }

};

class SinglyLinkedList2 {
public:
    node2* head;

    SinglyLinkedList2() {
        head = NULL;
    }
    SinglyLinkedList2(node2* n) {
        head = n;
    }


    // 2. Append a node to the list
    void appendNode(node2* n)
    {

        if (head == NULL) {
            head = n;
        }
        else {
            node2* ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = n;
        }
    }

};


int main() {

    SinglyLinkedList s;
    SinglyLinkedList2 s2;
    int temp;
    char ch;
    int temperature_input, ph_input;
    int humidity_input;
    int rainfall_input;
    int N2, P2, K2;
    int ph2, N_input, P_input, K_input;
    int humid;
    int rain, ctemp;
    string label_input, city, C_temp, input_city;
    string choice, crop;
    system("color f0");


    //set to the csv file location and reading input from csv file
    ifstream csv_file("crop_rec3.txt");
    ifstream csv_file2("avg-temp.txt");

    if (!csv_file.is_open())
    {
        std::cout << "File Not Open" << '\n';
        exit(0);

    }

    if (!csv_file2.is_open())
    {
        std::cout << "File avg-temp Not Open" << '\n';
        exit(0);

    }
    do
    {

        cout << "\n\n";


        cout << "                    ***          ***                                       ***          ***                                    ***          ***                   \n";
        cout << "                 ***....**     **...***                                ***....**     **...***                               ***....**     **...***                \n";
        cout << "               **........** **.......**                              **........** **.......**                              **........** **.......**               \n";
        cout << "         ***    **..........*.........**    ***                ***    **..........*.........**    ***              ***    **..........*.........**    ***         \n";
        cout << "     **.....**  **..................**  **.....**          **.....**  **..................**  **.....**         **.....**  **..................**  **.....**      \n";
        cout << "   **.........**  **..............**  **.........**      **.........**  **..............**  **.........**      **.........**  **..............**  **.........**   \n";
        cout << "   *..............*   *..........*   *..............*    *..............*   *..........*   *..............*    *..............*   *..........*   *..............* \n";
        cout << "    **..............*   *......*   *..............**      **..............*   *......*   *..............**      **..............*   *......*   *..............**  \n";
        cout << "      **..............** *....* **..............**          **..............** *....* **..............**          **..............** *....* **..............**    \n";
        cout << "        *......................................*              *......................................*              *......................................*      \n";
        cout << "      **..............**........**..............**          **..............**........**..............**          **..............**........**..............**    \n";
        cout << "    **..............*    *....*    *..............**       **..............*    *....*    *..............**       **..............*    *....*    *..............**\n";
        cout << "   *..............*      *....*      *..............*    *..............*      *....*      *..............*    *..............*      *....*      *..............* \n";
        cout << "    **.........**        *....*        **.........**      **.........**        *....*        **.........**      **.........**        *....*        **.........**  \n";
        cout << "      **.....**         *....*           **.....**          **.....**         *....*           **.....**          **.....**         *....*           **.....**    \n";
        cout << "         ***          **....*               ***                ***          **....*               ***                ***          **....*               ***       \n";
        cout << "                    ** * * *                                               ** * * *                                               ** * * *                        \n";


        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "                                                   WELCOME          TO          CROP          RECOMMENDATION          SYSTEM\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\n\n";



        // Empty vector holding all data from csv file
        vector<string> row;
        string row_data;

        //input variable declare here

        cout << "1.Crop recommendation according to geography\n";
        cout << "2.Advanced search\n";
        cout << "3.Economics and global data about crops\n";

        cin >> choice;
        cout << "\n\n";
        if (choice == "1")
        {
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << "                                                                                               Crop recommendation according to geography\n";
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\n\n";


            cout << "Please enter your city name" << endl;
            cin >> input_city;

            while (csv_file2.good())
            {

                getline(csv_file2, city, ',');
                getline(csv_file2, C_temp, '\n');

                if (input_city == city)
                {
                    istringstream(C_temp) >> ctemp;

                }

            }
            csv_file2.close();


            cout << endl << endl;
            cout << "These crops are suitable in your city according to your city's average temperature" << endl;

            while (csv_file.good())
            {
                Node* n1 = new Node();

                getline(csv_file, n1->n, ',');
                getline(csv_file, n1->p, ',');
                getline(csv_file, n1->k, ',');
                getline(csv_file, n1->temperature, ',');
                getline(csv_file, n1->humidity, ',');
                getline(csv_file, n1->ph, ',');
                getline(csv_file, n1->rainfall, ',');
                getline(csv_file, n1->label, '\n');
                s.appendNode(n1);
                istringstream(n1->temperature) >> temp;
                istringstream(n1->humidity) >> humid;
                istringstream(n1->rainfall) >> rain;
                istringstream(n1->ph) >> ph2;




                if (ctemp == temp)
                {
                    if (crop != n1->label)
                    {
                        crop = n1->label;

                        cout << "   " << crop << "\n";

                    }

                }
            }
            cout << "\n\n\nTO  EXIT  THE  PROGRAM PLEASE PRESS n OR TO CONTINUE PRESS y :";
            cin >> ch;

        }





        if (choice == "2")
        {
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << "                                                                                                        Advanced search\n";
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\n\n";

            cout << "1.Search by soil condition\n";
            cout << "2.Search by weather condition\n";
            cout << "3.Search by label\n";



            cout << "\nEnter the number to choose a program: ";
            cin >> choice;

            //Searching by temperature conditions data from csv file

            if (choice == "1")
            {
                cout << "Enter the soil ph: ";
                cin >> ph_input;
                cout << "Enter the soil nitrogen level: ";
                cin >> N_input;
                cout << "Enter the soil phosphorus : ";
                cin >> P_input;
                cout << "Enter the soil potassium : ";
                cin >> K_input;
                cout << endl << endl;

                cout << "N   P   K   temperature   humidity   ph   rainfall   label" << endl << endl;
                while (csv_file.good())
                {
                    Node* n1 = new Node();

                    getline(csv_file, n1->n, ',');
                    getline(csv_file, n1->p, ',');
                    getline(csv_file, n1->k, ',');
                    getline(csv_file, n1->temperature, ',');
                    getline(csv_file, n1->humidity, ',');
                    getline(csv_file, n1->ph, ',');
                    getline(csv_file, n1->rainfall, ',');
                    getline(csv_file, n1->label, '\n');

                    istringstream(n1->temperature) >> temp;
                    istringstream(n1->humidity) >> humid;
                    istringstream(n1->rainfall) >> rain;
                    istringstream(n1->ph) >> ph2;
                    istringstream(n1->n) >> N2;
                    istringstream(n1->p) >> P2;
                    istringstream(n1->k) >> K2;


                    s.appendNode(n1);


                    if (ph_input <= ph2 && ph_input + 1 > ph2 && N_input - 10 <= N2 && N_input + 10 > N2 && K_input - 10 <= K2 && K_input + 10 > K2 && P_input - 10 <= P2 && P_input + 10 > P2)
                    {
                        std::cout << n1->n << "  " << n1->p << "  " << n1->k << "       " << temp << "c          " << humid << "       " << ph2 << "     " << rain << "mm    " << n1->label << '\n';
                    }
                }


                cout << "\n\n\nTO  EXIT  THE  PROGRAM PLEASE PRESS n OR TO CONTINUE PRESS y :";
                cin >> ch;
            }

            //Searching by weather conditions data from csv file
            if (choice == "2")
            {

                cout << "Enter the average temperature in celsius: ";
                cin >> temperature_input;
                cout << "Enter the humidity: ";
                cin >> humidity_input;
                cout << "Enter the annual rainfall in mm: ";
                cin >> rainfall_input;
                cout << endl << endl;

                cout << "N   P   K   temperature   humidity   ph   rainfall   label" << endl << endl;

                while (csv_file.good())
                {
                    Node* n1 = new Node();

                    getline(csv_file, n1->n, ',');
                    getline(csv_file, n1->p, ',');
                    getline(csv_file, n1->k, ',');
                    getline(csv_file, n1->temperature, ',');
                    getline(csv_file, n1->humidity, ',');
                    getline(csv_file, n1->ph, ',');
                    getline(csv_file, n1->rainfall, ',');
                    getline(csv_file, n1->label, '\n');

                    s.appendNode(n1);
                    istringstream(n1->temperature) >> temp;
                    istringstream(n1->humidity) >> humid;
                    istringstream(n1->rainfall) >> rain;


                    if (temperature_input <= temp && temperature_input + 1 > temp && humidity_input - 5 <= humid && humidity_input + 10 > humid && rainfall_input - 10 <= rain && rainfall_input + 10 > rain)
                    {
                        std::cout << n1->n << "  " << n1->p << "  " << n1->k << "       " << temp << "c          " << humid << "       " << ph2 << "     " << rain << "mm    " << n1->label << '\n';
                    }
                }

                cout << "\n\n\nTO  EXIT  THE  PROGRAM PLEASE PRESS n OR TO CONTINUE PRESS y :";
                cin >> ch;
            }




            //Searching label data from csv file
            if (choice == "3")
            {
                cout << "Enter the label: ";
                cin >> label_input;
                cout << endl << endl;
                cout << "N   P   K   temperature   humidity   ph   rainfall   label" << endl << endl;

                while (csv_file.good())
                {
                    Node* n1 = new Node();

                    getline(csv_file, n1->n, ',');
                    getline(csv_file, n1->p, ',');
                    getline(csv_file, n1->k, ',');
                    getline(csv_file, n1->temperature, ',');
                    getline(csv_file, n1->humidity, ',');
                    getline(csv_file, n1->ph, ',');
                    getline(csv_file, n1->rainfall, ',');
                    getline(csv_file, n1->label, '\n');

                    istringstream(n1->temperature) >> temp;
                    istringstream(n1->humidity) >> humid;
                    istringstream(n1->rainfall) >> rain;
                    istringstream(n1->ph) >> ph2;


                    s.appendNode(n1);

                    if (label_input == n1->label)
                    {
                        std::cout << n1->n << "  " << n1->p << "  " << n1->k << "       " << temp << "c          " << humid << "       " << ph2 << "     " << rain << "mm    " << n1->label << '\n';
                    }
                }

                cout << "\n\n\nTO  EXIT  THE  PROGRAM PLEASE PRESS n OR TO CONTINUE PRESS y :";
                cin >> ch;
            }
        }

        if (choice == "3")
        {
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << "                                                                                                     Economics and global data about crops\n";
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            cout << "\n\n";

            int y;
			cout<<"1. Countries Starting From A-B."<<endl;		//File 1
			cout<<"2. Countries Starting From B-C."<<endl;		//File 2
			cout<<"3. Countries Starting From C-G."<<endl;		//File 3
			cout<<"4. Countries Starting From G-I."<<endl;		//File 4
			cout<<"5. Countries Starting From I-L."<<endl;		//File 5
			cout<<"6. Countries Starting From L-N."<<endl;		//File 6
			cout<<"7. Countries Starting From N-P."<<endl;		//File 7
			cout<<"8. Countries Starting From P-S."<<endl;		//File 8 & 9		
			cout<<"9. Countries Starting From S-U."<<endl;		//File 10
			cout<<"10. Countries Starting From U-E."<<endl;		//File 11
			cout<<"11. Countries Starting From E-S."<<endl;		//File 12
			cout<<"12. Countries Starting From S-P."<<endl;		//File 13
			cout<<"13. Other Countries & Islands."<<endl;		//File 14
            cout<<endl;
			cout<<"Enter the Choice: "<<endl;
			cin>>y;
            string area_c;
            string area, country;
            string item_c;
            string item;
            string element_c;
            string element;
            string year_c;
            string year;
            string unit;
            string value;
            string flag, name;
            int val, v;
            cout << "please enter your crop name :";
            cin >> name;
            cout << "\n\n";
        
			if(y==1){
			
		    ifstream csv_file3("file1.csv");
		
            if (!csv_file3.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }

            while (csv_file3.good())
            {
                getline(csv_file3, area_c, ',');
                getline(csv_file3, area, ',');

                if (country != area) {
                    getline(csv_file3, item_c, ',');
                    getline(csv_file3, item, ',');
                    getline(csv_file3, element_c, ',');
                    getline(csv_file3, element, ',');
                    getline(csv_file3, year_c, ',');
                    getline(csv_file3, year, ',');
                    getline(csv_file3, unit, ',');
                    getline(csv_file3, value, ',');
                    getline(csv_file3, flag, '\n');


                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " <<year_c << "    " <<year << "    " << unit << "    " << value << "    " << flag << endl<<endl;

                    }
                }
            }
		
	            csv_file3.close();

		}
		

		else if(y==2){
		
            ifstream csv_file4("file2.csv");

            if (!csv_file4.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file4.good())
            {
                getline(csv_file4, area_c, ',');
                getline(csv_file4, area, ',');

                if (country != area) {
                    getline(csv_file4, item_c, ',');
                    getline(csv_file4, item, ',');
                    getline(csv_file4, element_c, ',');
                    getline(csv_file4, element, ',');
                    getline(csv_file4, year_c, ',');
                    getline(csv_file4, year, ',');
                    getline(csv_file4, unit, ',');
                    getline(csv_file4, value, ',');
                    getline(csv_file4, flag, '\n');


                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag << endl<<endl;

                    }
                }
            }
            csv_file4.close();
		}

			else if(y==3){
				
			
            ifstream csv_file5("file3.csv");

            if (!csv_file5.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file5.good())
            {
                getline(csv_file5, area_c, ',');
                getline(csv_file5, area, ',');

                if (country != area) {
                    getline(csv_file5, item_c, ',');
                    getline(csv_file5, item, ',');
                    getline(csv_file5, element_c, ',');
                    getline(csv_file5, element, ',');
                    getline(csv_file5, year_c, ',');
                    getline(csv_file5, year, ',');
                    getline(csv_file5, unit, ',');
                    getline(csv_file5, value, ',');
                    getline(csv_file5, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file5.close();
		}


			else if(y==4){
				
			
            ifstream csv_file6("file4.csv");

            if (!csv_file6.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file6.good())
            {
                getline(csv_file6, area_c, ',');
                getline(csv_file6, area, ',');

                if (country != area) {
                    getline(csv_file6, item_c, ',');
                    getline(csv_file6, item, ',');
                    getline(csv_file6, element_c, ',');
                    getline(csv_file6, element, ',');
                    getline(csv_file6, year_c, ',');
                    getline(csv_file6, year, ',');
                    getline(csv_file6, unit, ',');
                    getline(csv_file6, value, ',');
                    getline(csv_file6, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file6.close();
		}


			else if(y==5){
				
			
            ifstream csv_file7("file5.csv");

            if (!csv_file7.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file7.good())
            {
                getline(csv_file7, area_c, ',');
                getline(csv_file7, area, ',');

                if (country != area) {
                    getline(csv_file7, item_c, ',');
                    getline(csv_file7, item, ',');
                    getline(csv_file7, element_c, ',');
                    getline(csv_file7, element, ',');
                    getline(csv_file7, year_c, ',');
                    getline(csv_file7, year, ',');
                    getline(csv_file7, unit, ',');
                    getline(csv_file7, value, ',');
                    getline(csv_file7, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file7.close();
		}


			else if(y==6){
				
			
            ifstream csv_file8("file6.csv");

            if (!csv_file8.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file8.good())
            {
                getline(csv_file8, area_c, ',');
                getline(csv_file8, area, ',');

                if (country != area) {
                    getline(csv_file8, item_c, ',');
                    getline(csv_file8, item, ',');
                    getline(csv_file8, element_c, ',');
                    getline(csv_file8, element, ',');
                    getline(csv_file8, year_c, ',');
                    getline(csv_file8, year, ',');
                    getline(csv_file8, unit, ',');
                    getline(csv_file8, value, ',');
                    getline(csv_file8, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file8.close();
		}


			else if(y==7){
				
			
            ifstream csv_file9("file7.csv");

            if (!csv_file9.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file9.good())
            {
                getline(csv_file9, area_c, ',');
                getline(csv_file9, area, ',');

                if (country != area) {
                    getline(csv_file9, item_c, ',');
                    getline(csv_file9, item, ',');
                    getline(csv_file9, element_c, ',');
                    getline(csv_file9, element, ',');
                    getline(csv_file9, year_c, ',');
                    getline(csv_file9, year, ',');
                    getline(csv_file9, unit, ',');
                    getline(csv_file9, value, ',');
                    getline(csv_file9, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file9.close();
		}


			else if(y==8){
				
			
            ifstream csv_file10("file8.csv");

            if (!csv_file10.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file10.good())
            {
                getline(csv_file10, area_c, ',');
                getline(csv_file10, area, ',');

                if (country != area) {
                    getline(csv_file10, item_c, ',');
                    getline(csv_file10, item, ',');
                    getline(csv_file10, element_c, ',');
                    getline(csv_file10, element, ',');
                    getline(csv_file10, year_c, ',');
                    getline(csv_file10, year, ',');
                    getline(csv_file10, unit, ',');
                    getline(csv_file10, value, ',');
                    getline(csv_file10, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file10.close();

            ifstream csv_file11("file9.csv");

            if (!csv_file11.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file11.good())
            {
                getline(csv_file11, area_c, ',');
                getline(csv_file11, area, ',');

                if (country != area) {
                    getline(csv_file11, item_c, ',');
                    getline(csv_file11, item, ',');
                    getline(csv_file11, element_c, ',');
                    getline(csv_file11, element, ',');
                    getline(csv_file11, year_c, ',');
                    getline(csv_file11, year, ',');
                    getline(csv_file11, unit, ',');
                    getline(csv_file11, value, ',');
                    getline(csv_file11, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file11.close();

		}


			else if(y==9){
				
			
            ifstream csv_file12("file10.csv");

            if (!csv_file12.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file12.good())
            {
                getline(csv_file12, area_c, ',');
                getline(csv_file12, area, ',');

                if (country != area) {
                    getline(csv_file12, item_c, ',');
                    getline(csv_file12, item, ',');
                    getline(csv_file12, element_c, ',');
                    getline(csv_file12, element, ',');
                    getline(csv_file12, year_c, ',');
                    getline(csv_file12, year, ',');
                    getline(csv_file12, unit, ',');
                    getline(csv_file12, value, ',');
                    getline(csv_file12, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file12.close();
		}


			else if(y==10){
				
			
            ifstream csv_file13("file11.csv");

            if (!csv_file13.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file13.good())
            {
                getline(csv_file13, area_c, ',');
                getline(csv_file13, area, ',');

                if (country != area) {
                    getline(csv_file13, item_c, ',');
                    getline(csv_file13, item, ',');
                    getline(csv_file13, element_c, ',');
                    getline(csv_file13, element, ',');
                    getline(csv_file13, year_c, ',');
                    getline(csv_file13, year, ',');
                    getline(csv_file13, unit, ',');
                    getline(csv_file13, value, ',');
                    getline(csv_file13, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file13.close();
		}


			else if(y==11){
				
			
            ifstream csv_file14("file12.csv");

            if (!csv_file14.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file14.good())
            {
                getline(csv_file14, area_c, ',');
                getline(csv_file14, area, ',');

                if (country != area) {
                    getline(csv_file14, item_c, ',');
                    getline(csv_file14, item, ',');
                    getline(csv_file14, element_c, ',');
                    getline(csv_file14, element, ',');
                    getline(csv_file14, year_c, ',');
                    getline(csv_file14, year, ',');
                    getline(csv_file14, unit, ',');
                    getline(csv_file14, value, ',');
                    getline(csv_file14, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file14.close();
		}


			else if(y==12){
				
			
            ifstream csv_file15("file13.csv");

            if (!csv_file15.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file15.good())
            {
                getline(csv_file15, area_c, ',');
                getline(csv_file15, area, ',');

                if (country != area) {
                    getline(csv_file15, item_c, ',');
                    getline(csv_file15, item, ',');
                    getline(csv_file15, element_c, ',');
                    getline(csv_file15, element, ',');
                    getline(csv_file15, year_c, ',');
                    getline(csv_file15, year, ',');
                    getline(csv_file15, unit, ',');
                    getline(csv_file15, value, ',');
                    getline(csv_file15, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file15.close();
		}


			else if(y==13){
				
			
            ifstream csv_file16("file13.csv");

            if (!csv_file16.is_open())
            {
                std::cout << "File Not Open" << '\n';
                exit(0);

            }


            while (csv_file16.good())
            {
                getline(csv_file16, area_c, ',');
                getline(csv_file16, area, ',');

                if (country != area) {
                    getline(csv_file16, item_c, ',');
                    getline(csv_file16, item, ',');
                    getline(csv_file16, element_c, ',');
                    getline(csv_file16, element, ',');
                    getline(csv_file16, year_c, ',');
                    getline(csv_file16, year, ',');
                    getline(csv_file16, unit, ',');
                    getline(csv_file16, value, ',');
                    getline(csv_file16, flag, '\n');

                    istringstream(value) >> val;



                    if (name == item)
                    {
                        country = area;

                        std::cout << area_c << "  " << area << "  " << item_c << "       " << item << "          " << element_c << "       " << element << "     " << year_c << "    " << year << "    " << unit << "    " << value << "    " << flag <<endl<<endl;

                    }
                }
            }


            csv_file16.close();
		}


            cout << "\n\n\nTO  EXIT  THE  PROGRAM PLEASE PRESS n OR TO CONTINUE PRESS y :";
            cin >> ch;
        }






    } while (ch != 'n');
    return 0;
}
