#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/* ----- Define function -----*/
string Menu();
void Add_infor(string Patient[1000][2]);
void Filling(string Patient[1000][2] , string his_Patient[1000][5] , float money[1000][5] , float &total);
void Scraping(string Patient[1000][2] , string his_Patient[1000][5], float money[1000][5] , float &total);
void Extracting_teeth(string Patient[1000][2] , string his_Patient[1000][5], float money[1000][5] , float &total);
void Show_pat_one(string , string Patient[1000][2] , string his_Patient[1000][5]);
void Show_Amount(float &total);
void Show_pat_all(string Patient[1000][2] , string his_Patient[1000][5] , float money[1000][5]);
/*----------------------------*/

int main()
{
    float money[1000][5];
    float total = 0.0 ;
    string code , menu , ID , name ;
    string Patient[1000][2] = {/*Petient [0]*/"001" , "Kaittrakul"
            ,/*Petient [1]*/"002" , "Parinya"
            ,/*Petient [2]*/"003" , "Putcharapooml"
            ,/*Petient [3]*/"004" , "Aomsin"};

    string his_Patient[1000][5];
    for (int r = 0 ; r < 1000 ; r ++)
    {
        his_Patient[r][0] = Patient[r][0];
        for (int c = 1 ; c < 5 ; c++)
            his_Patient[r][c] = "" ;
    }

    for (int r = 0 ; r < 1000 ; r ++)
        for (int c = 0 ; c < 5 ; c ++)
            money[r][c] = 0.0 ;

    do
    {
        system("cls");
        menu = Menu();
        if (menu == "1") Add_infor(Patient);
        else if (menu == "2.1") Filling(Patient , his_Patient, money , total);
        else if (menu == "2.2") Scraping(Patient , his_Patient, money , total );
        else if (menu == "2.3") Extracting_teeth(Patient , his_Patient , money , total);
        else if (menu == "3.1")	Show_pat_one(code , Patient , his_Patient  );
        else if (menu == "3.2") Show_Amount(total);
        else if (menu == "3.3") Show_pat_all(Patient , his_Patient , money);

    }while(menu != "E" && menu != "e");
    system("cls");
    cout << "\nExit program . . . \n\n";
}
//===================================================  Function Select Menu  ==================================================//
string Menu()
{
    string menu ,submenu;
    menu = "";
    submenu = "";
    Me:
    cout << "======= Menu =======" << endl<< endl;
    cout << "1. Add Information" << endl;
    cout << "2. Treatment " << endl;
    cout << "3. Report" << endl;
    cout << "E. Exit program " << endl<< endl;
    cout << "====================" << endl<< endl;
    cout << "Select Menu : " ;
    cin >> menu ;
    if (menu != "1" && menu != "2" && menu != "3" && menu != "E" && menu != "e")
    {
        cout << endl;
        cout << "!! Enter 1 or 2 or 3 or E !!" << endl ;
        cout << "!! Enter again !!" << endl << endl;
        goto Me;
    }
    else if (menu != "3" && menu != "2")system("cls");
    else if (menu == "2")
    {
        Me2:
        cout << "	1. Filling" << endl;
        cout << "	2. Scraping" << endl;
        cout << "	3. Extracting teeth" << endl;
        cout << "Select submenu : ";
        cin >> submenu ;
        if (submenu != "1" && submenu != "2" && submenu != "3" )
        {
            cout << "!! Enter 1 or 2 or 3 !!" << endl ;
            cout << "!! Enter again !!" << endl << endl;
            goto Me2;
        }
        cout << endl ;
        cout << "====================" << endl<< endl;
        menu = menu + "." + submenu ;

    }
    else if (menu == "3")
    {
        Me3:
        cout << "	1. Report each patient treatment history." << endl;
        cout << "	2. Report Total treatment amount." << endl;
        cout << "	3. Report all patient treatment history." << endl ;
        cout << "Select submenu : ";
        cin >> submenu ;
        if (submenu != "1" && submenu != "2" && submenu != "3")
        {
            cout << "!! Enter 1 or 2 or 3  !!" << endl ;
            cout << "!! Enter again !!" << endl << endl;
            goto Me3;
        }
        cout << endl ;
        cout << "====================" << endl<< endl;
        system("cls");
        menu = menu + "." + submenu ;

    }
    return (menu);
}

//==============================================================================================================================//

//================================================ Function Add new information ================================================//

void Add_infor(string Patient[1000][2])
{
    char check_name;
    string name ;
    u:
    cout << "Searching for patient name : ";
    cin >> name ;
    for (int y = 0 ; y < name.length() ; y++)
    {
        if (name.at(y) >= '0' && name.at(y) <= '9')
        {
            cout << endl;
            cout << "====================" << endl << endl;
            cout << "Plese enter again !! ." << endl;
            cout << "You must Enter name." << endl << endl;
            cout << "====================" << endl << endl;
            goto u ;
        }
    }
    for (int i = 0 ; i < 1000 ; i++)
    {
        if (Patient[i][1] == name)
        {
            cout << "You have been treated." << endl ;
            cout << "You can't add new information." << endl << endl;
            cout << "------------------------------------------------" << endl<< endl;
            check_name = 'U';
            break;
        }else check_name = 'N';
    }
    if (check_name == 'N')
    {
        cout << "You never cure." << endl<< endl;
        cout << "====================" << endl<< endl;
        cout << "Add new information." << endl ;
        for (int i = 0 ; i < 1000 ; i++)
        {
            if (Patient[i][1].empty())
            {
                add_id_again :
                cout << "Enter New patient ID : " ;
                cin >> Patient[i][0] ;
                for(int count = 0 ; count < Patient[i][0].length() ; count ++)
                {
                    if (Patient[i][0].at(count) < '0' || Patient[i][0].at(count) > '9')
                    {
                        cout << endl;
                        cout << "====================" <<endl << endl;
                        cout << "Enter 000 - 999 " << endl;
                        goto add_id_again;
                    }
                    if ( Patient[i][0].length() < 3)
                    {
                        cout << endl;
                        cout << "====================" <<endl << endl;
                        cout << "Enter 000 - 999 " << endl;
                        goto add_id_again;
                    }
                }
                for (int o = 0 ; o < i ; o++)
                {
                    if (Patient[i][0] == Patient[o][0])
                    {
                        cout << "====================" << endl;
                        cout << "*** This ID is used." << endl;
                        cout << "====================" << endl<< endl;
                        goto add_id_again ;
                    }
                }
                cout << "Enter New patient Name : " ;
                cin >> Patient[i][1] ;
                cout << endl;
                cout << "====================" << endl<< endl;
                break;
            }else ;
        }
    }
}

//==============================================================================================================================//
//======================================================= Function Add history =================================================//
void Filling(string Patient[1000][2] , string his_Patient[1000][5], float money[1000][5] , float &total)
{
    char confirm;
    string id ;
    ID:
    cout << "Enter Patient ID : " ;
    cin >> id ;
    for(int z = 0 ; z < id.length() ; z ++)
    {
        if (id.at(z) < '0' || id.at(z) >'9')
            goto ID;
    }
    if (id.length() < 3 || id.length() > 3)
    {
        cout << "!! Enter 000 - 999 !!" << endl ;
        cout << "!! Enter again !!" << endl << endl;
        goto ID;
    }
    for (int r = 0 ; r < 1000 ; r++)
    {
        if (id == Patient[r][0])
        {
            cout << "	1. Filling" << endl;
            cout << "	Cost = 400" << endl;
            do
            {
                cout << endl;
                cout << "Enter (Y/N) to confirm  : " ;
                cin >> confirm ;
                if (confirm == 'Y' || confirm == 'y')
                {

                    for (int c = 1 ; c < 5 ; c++)
                    {
                        string C;
                        if (his_Patient[r][c].empty())
                        {
                            if (c == 1) C = "1.";
                            else if (c == 2) C= "2.";
                            else if (c == 3) C = "3.";
                            else if (c == 4) C = "4.";
                            else if (c == 5) C = "5.";
                            his_Patient[r][c] = his_Patient[r][c] + C + "Filling ." ;
                            total += 400;
                            break;
                        }
                    }
                }
            }while (confirm != 'Y' && confirm != 'y' && confirm != 'n' && confirm != 'N') ;
            system("cls");
            for (int m = 1 ; m < 5 ; m++)
            {
                if (money[r][m] == 0.0)
                {
                    money[r][m] += 400 ;
                    break;
                }
            }
            break;
        }else if (r == 99 && Patient[r][0] != id)
        {
            cout << "This ID isn't Data." << endl << endl;
            cout << "====================" << endl << endl ;
            Add_infor(Patient);
        }
    }

}

void Scraping(string Patient[1000][2] , string his_Patient[1000][5], float money[1000][5] , float &total)
{
    char confirm;
    string id ;
    ID2:
    cout << "Enter Patient ID : " ;
    cin >> id ;
    for(int z = 0 ; z < id.length() ; z ++)
    {
        if (id.at(z) < '0' || id.at(z) >'9')
            goto ID2;
    }
    if (id.length() < 3 || id.length() > 3)
    {
        cout << "!! Enter 000 - 999 !!" << endl ;
        cout << "!! Enter again !!" << endl << endl;
        goto ID2;
    }
    for (int r = 0 ; r < 1000 ; r++)
    {
        if (id == Patient[r][0])
        {
            cout << "	2. Scraping" << endl;
            cout << "	Cost = 600" << endl;
            do
            {
                cout << endl;
                cout << "Enter (Y/N) to confirm  : " ;
                cin >> confirm ;
                if (confirm == 'Y' || confirm == 'y')
                {

                    for (int c = 1 ; c < 5 ; c++)
                    {
                        string C;
                        if (his_Patient[r][c].empty())
                        {
                            if (c == 1) C = "1.";
                            else if (c == 2) C= "2.";
                            else if (c == 3) C = "3.";
                            else if (c == 4) C = "4.";
                            else if (c == 5) C = "5.";
                            his_Patient[r][c] = his_Patient[r][c] + C + "Scraping ." ;
                            total += 600;
                            break;
                        }
                    }
                }
            }while (confirm != 'Y' && confirm != 'y' && confirm != 'n' && confirm != 'N') ;
            system("cls");
            for (int m = 1 ; m < 5 ; m++)
            {
                if (money[r][m] == 0.0)
                {
                    money[r][m] += 600 ;
                    break;
                }
            }
            break;
        }else if (r == 99 && Patient[r][0] != id)
        {
            cout << "This ID isn't Data." << endl << endl;
            cout << "====================" << endl << endl ;
            Add_infor(Patient);
        }
    }
}

void Extracting_teeth(string Patient[1000][2] , string his_Patient[1000][5], float money[1000][5] , float &total)
{
    char confirm;
    string id ;
    ID3:
    cout << "Enter Patient ID : " ;
    cin >> id ;
    for(int z = 0 ; z < id.length() ; z ++)
    {
        if (id.at(z) < '0' || id.at(z) >'9')
            goto ID3;
    }
    if (id.length() < 3 || id.length() > 3)
    {
        cout << "!! Enter 000 - 999 !!" << endl ;
        cout << "!! Enter again !!" << endl << endl;
        goto ID3;
    }
    for (int r = 0 ; r < 1000 ; r++)
    {
        if (id == Patient[r][0])
        {
            cout << "	3. Extracting_teeth" << endl;
            cout << "	Cost = 500" << endl;
            do
            {
                cout << endl;
                cout << "Enter (Y/N) to confirm  : " ;
                cin >> confirm ;
                if (confirm == 'Y' || confirm == 'y')
                {

                    for (int c = 1 ; c < 5 ; c++)
                    {
                        string C;
                        if (his_Patient[r][c].empty())
                        {
                            if (c == 1) C = "1.";
                            else if (c == 2) C= "2.";
                            else if (c == 3) C = "3.";
                            else if (c == 4) C = "4.";
                            else if (c == 5) C = "5.";
                            his_Patient[r][c] = his_Patient[r][c] + C + "Extracting teeth." ;
                            total += 500;
                            break;
                        }
                    }
                }
            }while (confirm != 'Y' && confirm != 'y' && confirm != 'n' && confirm != 'N') ;
            system("cls");
            for (int m = 1 ; m < 5 ; m++)
            {
                if (money[r][m] == 0.0)
                {
                    money[r][m] += 500 ;
                    break;
                }
            }
            break;
        }else if (r == 99 && Patient[r][0] != id)
        {
            cout << "This ID isn't Data." << endl << endl;
            cout << "====================" << endl << endl ;
            Add_infor(Patient);
        }
    }
}


//==============================================================================================================================//
//================================================ Function Show patient one case history ======================================//
void Show_pat_one(string code , string Patient[1000][2] , string his_Patient[1000][5])
{
    char add_new;
    do
    {
        bool check = true ;
        code :
        cout << "Enter Pantient ID (0-exit) : ";
        cin >> code ;
        system("cls");
        if (code == "0") break;
        if (code.length() !=  3)
        {
            cout << "Enter code again. (000 - 999)" << endl << endl ;
            cout << "====================" << endl << endl ;
            goto code ;
        }
        for (int l = 0 ; l < 3 ; l ++)
        {
            if (code.at(l) > '9' || code.at(l) < '0')
            {
                cout << "Enter code again. (000 - 999)" << endl << endl ;
                cout << "====================" << endl << endl ;
                goto code ;
            }
        }

        for (int i = 0 ; i < 1000 ; i ++)
        {
            if(Patient[i][0] == code)
            {
                if (Patient[i][0].empty())
                {
                    cout << "======================================" << endl;
                    break;
                }
                cout << "\n***__Show patient one case history__***" << endl<< endl ;
                cout << " =>  Patient ID \t: " << Patient[i][0] << endl;
                cout << " =>  Name \t\t: " << Patient[i][1] << endl;
                for (int j = 1 ; j < 5 ; j ++)
                {
                    if (his_Patient[i][j] == "" && his_Patient[i][1] == "")
                    {
                        cout << " =>  case history \t: no info " << endl << endl ;
                        break;
                    }else if (j == 1)
                    {
                        if (his_Patient[i][j] == "")break;
                        cout << " =>  case history \t: " << his_Patient[i][j]  << endl ;
                    }else if (j > 1)
                    {
                        if (his_Patient[i][j] == "")break;
                        cout << "                  \t: " << his_Patient[i][j]  << endl ;
                    }
                }

                cout << endl;
                check = false ;
                break;
            }
        }
        if (check != false)
        {
            cout << "------------------------------------------------" << endl;
            cout << "This account does not exits ." << endl;
            cout << "Are you want to add nwe information ? ." << endl;
            do
            {
                cout << "Input (Y/N) : " ;
                cin >> add_new;
                cout << "------------------------------------------------" << endl;
                if (add_new == 'y' || add_new == 'Y')Add_infor(Patient);
            }while (add_new != 'y' && add_new != 'Y' && add_new != 'n' && add_new != 'Y');
        }
    }while(code != "0");
    cout << endl ;
}
//==============================================================================================================================//
//============================================== Function Show Total treatment Amount ==========================================//

void Show_Amount(float &total)
{

    cout << "====================" << endl << endl ;
    cout << "Total treatment Amount = " << total << endl << endl;
    cout << "====================" << endl << endl ;
    system("pause");
}

//==============================================================================================================================//
//============================================== Function Show patient all casetical history  ==================================//

void Show_pat_all(string Patient[1000][2] , string his_Patient[1000][5] , float money[1000][5])
{
    cout << "\n************______Patient medical hisyory______*************\n"<< endl;
    cout << ":" << setfill('=') << setw(57) << "="<< ":"<< endl;
    cout << setfill(' ')<< ":"  <<setw(7)<< "ID. :" << left << setw(17)  << "      Name" << ":"
         << setw(23) << "     Case history" << ":" <<setw(8)<< "  cost" << ":"  << endl ;
    cout << setfill('=') << setw(57) << ":" << "="<< ":"<< endl;
    for (int a = 0 ; a < 1000 ; a ++)
    {

        if (Patient[a][0] == "")
            break;
        if (his_Patient[a][1] == "")
        {
            cout << setfill(' ')<< ":  "  <<setw(4) << Patient[a][0] << ":  "<< left << setw(15) << Patient[a][1] << ":"
                 << "  " << setw(21) << "No info"<< ":" <<setw(8)<< "  -" << ":"  << endl ;
        }
        if(his_Patient[a][1] != "")
        {
            cout << setfill(' ')<< ":  "  <<setw(4) << Patient[a][0] << ":  "<< left << setw(15) << Patient[a][1] << ":"
                 << "  " << setw(21) << his_Patient[a][1]<< ":  " <<setw(6)<< money[a][1] << ":"  << endl ;

        }
        if(his_Patient[a][2] != "")
        {
            cout << setfill(' ')<< ":  "  <<setw(4) << " " << ":  "<< left << setw(15) << " " << ":"
                 << "  " << setw(21) << his_Patient[a][2]<< ":  " <<setw(6)<< money[a][2] << ":"  << endl ;
        }
        if(his_Patient[a][3] != "")
        {
            cout << setfill(' ')<< ":  "  <<setw(4) << " " << ":  "<< left << setw(15) << " " << ":"
                 << "  " << setw(21) << his_Patient[a][3]<< ":  " <<setw(6)<< money[a][3] << ":"  << endl ;
        }
        if(his_Patient[a][4] != "")
        {
            cout << setfill(' ')<< ":  "  <<setw(4) << " " << ":  "<< left << setw(15) << " " << ":"
                 << "  " << setw(21) << his_Patient[a][4]<< ":  " <<setw(6)<< money[a][4]<< ":"  << endl ;
        }
        if (his_Patient[a][1] != "" && his_Patient[a][2] == "")cout << setfill('=') << setw(57) << ":" << "="<< ":"<< endl;
        else if (his_Patient[a][2] != "" && his_Patient[a][3] == "")cout << setfill('=') << setw(57) << ":" << "="<< ":"<< endl;
        else if (his_Patient[a][4] != "" )cout << setfill('=') << setw(57) << ":" << "="<< ":"<< endl;
    }
    cout << endl << endl;
    system("pause");

}
//==============================================================================================================================/