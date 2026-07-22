#include<bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
#define ENTER       13
#define SPECIAL    -32
#define UP          72
#define DOWN        80
#define BACKSPACE   8

//Giao dien chung
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int selectMenu(string title, vector<string> options)
{
    int current = 0;
    int total = options.size();
    char key;
    while(true)
    {
        system("cls");
        setColor(11); // Mau vang
        cout <<  title;
        setColor(7);
        for (int i = 0; i < total; i++)
        {
            if (i == current)
            {
                setColor(160); // Nen xanh la, chu den
                cout << " >> " << options[i] << " << \n";  // Luu y
                setColor(7);
            }
            else
            {
                cout << "    " << options[i] << "\n";
            }
        }
        key = _getch();
        if (key == SPECIAL)
        {
            key = _getch();
            if (key == UP)
                current = (current - 1 + total) % total;
            else if (key == DOWN)
                current = (current + 1) % total;
        }
        else if (key == ENTER)
        {
            return current + 1;
        }
    }
}
void loadingBar()
{
    cout << "\n    Dang xu ly du lieu: ";
    setColor(10);
    char x = 219;
    for(int i = 0; i < 25; i++)
    {
        cout << x;   // x la mot khoi mau
        Sleep(50);
    }
    setColor(7);
    cout << "\n    Hoan tat!\n";
    Sleep(1000);
}
void printHeaderTable(string type)
{
    setColor(11); // xanh nhat
    cout << left << setw(15) << "MSSV"
         << left << setw(25) << "Ho va Ten"
         << left << setw(15) << "Ngay Sinh"
         << left << setw(20) << "Nganh Hoc"
         << left << setw(10) << "Khoa";
    if (type == "UNDERGRADUATE")
    {
        cout << left << setw(10) << "CPA";
    }
    else if (type == "POSTGRADUATE")
    {
        cout << left << setw(15) << "Diem HP"
             << left << setw(15) << "Diem NC"
             << left << setw(15) << "Diem BVLV";
    }
    cout << endl;
    int totalWidth = 85;
    if (type == "UNDERGRADUATE") totalWidth += 10;
    if (type == "POSTGRADUATE")  totalWidth += 45;
    for (int i = 0; i < totalWidth; i++)
        cout << "-"; // Ke duong gach
    cout << endl;
    setColor(7);
}

//Mot so ham chuan hoa
string chuanhoaTen(string name)
{
    string res, word;
    stringstream ss(name);
    while(ss >> word)
    {
        res += toupper(word[0]);
        for(int i = 1; i < word.length(); i++)
        {
            res += tolower(word[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    return res;
}
string chuanhoaNgaysinh(string ns)
{
    if(ns[2] != '/') ns = "0" + ns;
    if (ns[5] != '/') ns.insert(3, "0");
    return ns;
}
string chuanhoaNganh(string nganh)
{
    for (char &c : nganh)
    {
        if (isalpha((unsigned char)c))
        {
            c = toupper((unsigned char)c);
        }
    }
    return nganh;
}

class Student
{
protected:
    string mssv = "";
    string hoten = "";
    string ngaysinh = "";
    string nganh = "";
    string khoa = "";
public:
    Student() {}
    virtual ~Student() {}
    string getMSSV(){return mssv;}
    string getName(){return hoten;}
    string getBirth(){return ngaysinh;}
    string getCourse(){return nganh;}
    string getCourseyear(){return khoa;}

    void setMSSV(string x){mssv = x;}
    void setName(string x){hoten = x;}
    void setBirth(string x){ngaysinh = x;}
    void setCourse(string x){nganh = x;}
    void setCourseyear(string x){khoa = x;}

    virtual void input()
    {
        cout << "Nhap MSSV: ";
        cin >> mssv;
        cin.ignore();
        cout << "Nhap ho ten: ";
        getline(cin, hoten);
        cout << "Nhap ngay sinh(dd/mm/yy): ";
        cin >> ngaysinh;
        cout << "Nhap nganh hoc: ";
        cin >> nganh;
        cout << "Nhap khoa: ";
        cin >> khoa;
    }
    virtual void display()
    {
        cout << left << setw(15) << mssv
             << left << setw(25) << chuanhoaTen(hoten)
             << left << setw(15) << chuanhoaNgaysinh(ngaysinh)
             << left << setw(20) << chuanhoaNganh(nganh) << "K"
             << left << setw(10) << khoa;
    }
    virtual void savetoFile(ofstream& file)
    {
        file << mssv << endl;
        file << chuanhoaTen(hoten) << endl;
        file << chuanhoaNgaysinh(ngaysinh) << endl;
        file << chuanhoaNganh(nganh) << endl;
        file << khoa << endl;
    }
};

class undergraduateStudent : public Student
{
protected:
    double cpa = 0;
public:
    undergraduateStudent() : Student() {}
    double getCPA(){return cpa;}
    void setCPA(double x){cpa = x;}
    void input()
    {
        Student::input();
        cout << "Nhap diem CPA(0-4): ";
        cin >> cpa;
    }
    void display()
    {
        Student::display();

        cout << left << setw(10)
             << fixed << setprecision(2) << cpa;
    }
    void savetoFile(ofstream& file)
    {
        Student::savetoFile(file);
        file << fixed << setprecision(2) << cpa << "\n";
    }
};

class postgraduateStudent: public Student
{
protected:
    double courseworkMark;
    double researchMark;
    double defenseMark;
public:
    postgraduateStudent() {}
    virtual ~postgraduateStudent() {}
    double getCourseworkMark(){return courseworkMark;}
    double getResearchMark(){return researchMark;}
    double getDefenseMark(){return defenseMark;}
    void setCourseworkMark(double x){courseworkMark = x;}
    void setResearchMark(double x){researchMark = x;}
    void setDefenseMark(double x){defenseMark = x;}

    void input()
    {
        Student::input();
        cout << "Nhap diem hoc phan (0-10): ";
        cin >> courseworkMark;
        while (courseworkMark < 0 || courseworkMark > 10)
        {
            cout << "Nhap lai diem hoc phan (0-10): ";
            cin >> courseworkMark;
        }
        cout << "Nhap diem nghien cuu (0-10): ";
        cin >> researchMark;
        while (researchMark < 0 || researchMark > 10)
        {
            cout << "Nhap lai diem nghien cuu (0-10): ";
            cin >> researchMark;
        }

        cout << "Nhap diem bao ve (0-10): ";
        cin >> defenseMark;
        while (defenseMark < 0 || defenseMark > 10)
        {
            cout << "Nhap lai diem bao ve (0-10): ";
            cin >> defenseMark;
        }
        cin.ignore();
    }
    void display()
    {
        Student::display();
        cout << left << setw(15) << courseworkMark
             << left << setw(15) << researchMark
             << left << setw(15) << defenseMark;
    }
    void savetoFile(ofstream& file)
    {
        Student::savetoFile(file);
        file << courseworkMark << endl;
        file << researchMark << endl;
        file << defenseMark << endl;
    }
};

class manageStudent
{
    vector<undergraduateStudent*> underList;
    vector<postgraduateStudent*> postList;
public:
    ~manageStudent()
    {
        for (auto s : underList)
        {
            delete s;
        }
        underList.clear();

        for (auto s : postList)
        {
            delete s;
        }
        postList.clear();
    }
    void loadFiletoList(string type)
    {
        if(type == "UNDERGRADUATE")
        {
            for(auto s : underList) delete s;
            underList.clear();

            ifstream fileUnder("undergraduate.txt");
            if(!fileUnder.is_open()) return;

            string mssv;
            while(getline(fileUnder, mssv))
            {
                if(mssv.empty()) continue;
                auto* s = new undergraduateStudent();
                s->setMSSV(mssv);

                string temp;
                getline(fileUnder, temp);
                s->setName(temp);
                getline(fileUnder, temp);
                s->setBirth(temp);
                getline(fileUnder, temp);
                s->setCourse(temp);
                getline(fileUnder, temp);
                s->setCourseyear(temp);

                double cpa;
                fileUnder >> cpa;
                fileUnder.ignore();
                s->setCPA(cpa);

                string dash;
                getline(fileUnder, dash);  // bo qua dau --- trong file

                underList.push_back(s);
            }
            fileUnder.close();
        }
    else if(type == "POSTGRADUATE")
    {
        for(auto s : postList) delete s;
        postList.clear();

        ifstream filePost("postgraduate.txt");
        if(!filePost.is_open())
        {
            cout << "Khong mo duoc file POSTGRADUATE!\n";
            return;
        }

        string mssv;
        while(getline(filePost, mssv))
        {
            if(mssv.empty()) continue;

            auto* s = new postgraduateStudent();
            s->setMSSV(mssv);

            string temp;
            getline(filePost, temp);
            s->setName(temp);
            getline(filePost, temp);
            s->setBirth(temp);
            getline(filePost, temp);
            s->setCourse(temp);
            getline(filePost, temp);
            s->setCourseyear(temp);

            double m1, m2, m3;
            filePost >> m1 >> m2 >> m3;
            filePost.ignore();
            s->setCourseworkMark(m1);
            s->setResearchMark(m2);
            s->setDefenseMark(m3);

            string dash;
            getline(filePost, dash);

            postList.push_back(s);
        }

        filePost.close();
    }
}
    template<typename T>
    bool insertByMSSV(vector<T*> &v, T* s)
    {
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            if ((*it)->getMSSV() == s->getMSSV())
            {
                cout << "Sinh vien da ton tai! Cap nhat thong tin.\n";
                Sleep(1000);
                return false;
            }
            if ((*it)->getMSSV() > s->getMSSV())
            {
                v.insert(it, s);
                return true;
            }
        }
        v.push_back(s);
        return true;
    }

    void saveFile()
    {
        ofstream fileUnder("undergraduate.txt");  //ofstream: xoa va ghi moi
        if (fileUnder.is_open())
        {
            for (auto *s : underList)
            {
                s->savetoFile(fileUnder);
                fileUnder << "---\n";
            }
            fileUnder.close();
        }
        ofstream filePost("postgraduate.txt");
        if (filePost.is_open())
        {

            for (auto *s : postList)
            {
                s->savetoFile(filePost);
                filePost << "---\n";
            }
            filePost.close();
        }
    }

    // 1. Them (va sap xep theo thu tu MSSV)
    void addByMSSV()
    {
        int choice = selectMenu("BAN MUON THEM LOAI SINH VIEN NAO?\n", {"Sinh vien dai hoc",
                                                                        "Sinh vien sau dai hoc",
                                                                        "Quay lai"});

        if (choice == 3) return;

        else if(choice == 1)
        {
            loadFiletoList("UNDERGRADUATE");
            undergraduateStudent* s = new undergraduateStudent();
            s->input();
            if (insertByMSSV(underList, s))
            {
                saveFile();
                loadingBar();
            }
            else
            {
                delete s;
            }
        }
        else
        {
            loadFiletoList("POSTGRADUATE");
            postgraduateStudent* s = new postgraduateStudent();
            s->input();
            if (insertByMSSV(postList, s))
            {
                saveFile();
                loadingBar();
            }
            else
            {
                delete s;
            }
        }
    }
    //2.Xoa
    void deleteByMSV()
    {
        while(true)
    {
        int choice = selectMenu("BAN MUON XOA SINH VIEN NAO?\n",{"Sinh vien dai hoc",
                                                               "Sinh vien sau dai hoc",
                                                               "Quay lai menu chinh"});
            if (choice == 3) return;
            system("cls");
            setColor(14);
            cout << "--- XOA SINH VIEN KHOI HE THONG ---\n";
            setColor(7);
            cout << "Nhap MSSV cua sinh vien can xoa: ";
            string mssv;
            cin >> mssv;
            bool found = false;
            bool deleted = false;
            if(choice == 1)
            {
                loadFiletoList("UNDERGRADUATE");
                for(auto s = underList.begin(); s != underList.end(); s++)
                {
                    if((*s)->getMSSV() == mssv)
                    {
                        found = true;

                        system("cls");
                        setColor(12); // Mau do
                        cout << "\nCANH BAO!!!\nBAN DANG YEU CAU XOA SINH VIEN NAY:\n";
                        setColor(7);

                        printHeaderTable("UNDERGRADUATE");
                        (*s)->display();
                        cout << endl;
                        Sleep(5000);

                        cout << "\n--------------------------------------------------\n";
                        int confirm = selectMenu("HANH DONG NAY KHONG THE HOAN TAC. BAN CHAC CHAN CHU?\n",{"Khong!Huy thao tac.",
                                                                                                          "Co, xoa ngay lap tuc!"
                        });
                        if(confirm == 1)
                        {
                            setColor(11); // Mau xanh duong
                            cout << "\n >> Da huy thao tac xoa!\n";
                            setColor(7);
                            cout << "\nNhan phim bat ky de tiep tuc...";
                            _getch();
                        }
                        if(confirm == 2)
                        {
                            s= underList.erase(s);
                            delete *s;
                            saveFile();
                            loadingBar();
                            setColor(10); // Mau xanh
                            cout << "\n >> DA XOA THANH CONG RA KHOI DU LIEU!\n";
                            setColor(7);
                            break;
                        }
                    }
                }
            }
            else
            {
                loadFiletoList("POSTGRADUATE");
                for(auto s = postList.begin(); s != postList.end(); ++s)
                {
                    if((*s)->getMSSV() == mssv)
                    {
                        found = true;
                        system("cls");
                        setColor(12);
                        cout << "\nCANH BAO!!!\nBAN DANG YEU CAU XOA SINH VIEN NAY:\n";
                        setColor(7);
                        printHeaderTable("POSTGRADUATE");
                        (*s)->display();
                        Sleep(5000);
                        int confirm = selectMenu("HANH DONG NAY KHONG THE HOAN TAC. BAN CHAC CHAN CHU?\n", {"Khong! Huy thao tac",
                                                                                                            "Co, xoa ngay lap tuc!"});
                        if(confirm == 1)
                        {
                            setColor(11);
                            cout << "\n >> Da huy thao tac xoa!\n";
                            setColor(7);
                            cout << "\nNhan phim bat ky de tiep tuc...";
                            _getch();
                        }
                        if(confirm == 2)
                        {
                            s = postList.erase(s);
                            delete *s;
                            saveFile();
                            loadingBar();
                            setColor(10);
                            cout << "\n >> DA XOA THANH CONG RA KHOI DU LIEU!\n";
                            setColor(7);
                            break;
                        }
                    }
                }
                if(!found)
                {
                    setColor(14);
                    cout << "\n >> Khong tim thay sinh vien co MSSV: " << mssv << "\n";
                    setColor(7);
                }
            }
        }
    }

    //3. Sua thong tin
    void editInfo()
    {
        while(true)
        {
            int choice = selectMenu("BAN MUON SUA THONG TIN O DANH SACH NAO?\n", {"Sinh vien dai hoc",
                                                                                "Sinh vien dau dai hoc",
                                                                                "Quay lai menu chinh"});
            if (choice == 3) return;
            system("cls");
            setColor(14);
            cout << "--- SUA THONG TIN SINH VIEN ---\n";
            setColor(7);
            cout << "Nhap MSSV cua sinh vien can sua: ";
            string mssv;
            cin >> mssv;
            bool found = false;
            if (choice == 1)
            {
                loadFiletoList("UNDERGRADUATE");
                for (auto *s : underList)
                {
                    if (s->getMSSV() == mssv)
                    {
                        found = true;
                        while(true)
                        {
                            system("cls");
                            cout << ">> DANG SUA THONG TIN CHO SINH VIEN:\n";
                            printHeaderTable("UNDERGRADUATE");
                            s->display();
                            cout << "\n";
                            Sleep(2000);
                            vector<string> opts ={"Sua MSSV",
                                                "Sua ho va ten",
                                                "Sua ngay sinh",
                                                "Sua nganh hoc",
                                                "Sua khoa (K)",
                                                "Sua diem CPA",
                                                "Hoan tat (Luu & Quay lai)"};
                            int opt = selectMenu("CHON THONG TIN MUON SUA:\n", opts);

                            if (opt == 7) return;

                            cout << "\n[Nhap du lieu moi]: ";

                            if(opt == 1)
                            {
                                string val;
                                cout << "MSSV moi: ";
                                cin >> val;
                                s->setMSSV(val);
                            }
                            else if(opt == 2)
                            {
                                cin.ignore();
                                string val;
                                cout << "Ho ten moi: ";
                                getline(cin, val);
                                chuanhoaTen(val);
                                s->setName(val);
                            }
                            else if(opt == 3)
                            {
                                string val;
                                cout << "Ngay sinh moi (dd/mm/yyyy): ";
                                cin >> val;
                                chuanhoaNgaysinh(val);
                                s->setBirth(val);
                            }
                            else if(opt == 4)
                            {
                                string val;
                                cout << "Nganh hoc moi: ";
                                cin >> val;
                                chuanhoaNganh(val);
                                s->setCourse(val);
                            }
                            else if(opt == 5)
                            {
                                string val;
                                cout << "Khoa moi: ";
                                cin >> val;
                                s->setCourseyear(val);
                            }
                            else if(opt == 6)
                            {
                                double val;
                                cout << "Diem CPA moi: ";
                                cin >> val;
                                s->setCPA(val);
                            }
                            saveFile();
                            loadingBar();
                            break;
                        }
                    }
                }
            }
            else
            {
                loadFiletoList("POSTGRADUATE");
                for (auto *s : postList)
                {
                    if (s->getMSSV() == mssv)
                    {
                        found = true;
                        while(true)
                        {
                            system("cls");
                            cout << ">> DANG SUA THONG TIN CHO SINH VIEN:\n";
                            printHeaderTable("UNDERGRADUATE");
                            s->display();
                            cout << "\n";
                            Sleep(2000);
                            vector<string> opts ={"Sua MSSV",
                                                "Sua ho ten",
                                                "Sua ngay sinh",
                                                "Sua nganh",
                                                "Sua khoa",
                                                "Sua diem hoc phan",
                                                "Sua diem nghien cuu",
                                                "Sua diem bao ve",
                                                "Hoan tat (Luu & Quay lai)"};
                            int opt = selectMenu("CHON THONG TIN MUON SUA:", opts);

                            if (opt == 9) return;

                            cout << "\n[Nhap du lieu moi]: ";
                            if(opt == 1)
                            {
                                string val;
                                cout<<"MSSV moi: ";
                                cin>>val;
                                s->setMSSV(val);
                            }
                            else if(opt == 2)
                            {
                                cin.ignore();
                                string val;
                                cout<<"Ten moi: ";
                                getline(cin,val);
                                chuanhoaTen(val);
                                s->setName(val);
                            }
                            else if(opt == 3)
                            {
                                string val;
                                cout<<"Ngay sinh moi: ";
                                cin>>val;
                                chuanhoaNgaysinh(val);
                                s->setBirth(val);
                            }
                            else if(opt == 4)
                            {
                                string val;
                                cout<<"Nganh moi: ";
                                cin>>val;
                                chuanhoaNganh(val);
                                s->setCourse(val);
                            }
                            else if(opt == 5)
                            {
                                string val;
                                cout<<"Khoa moi: ";
                                cin>>val;
                                s->setCourseyear(val);
                            }
                            else if(opt == 6)
                            {
                                double val;
                                cout<<"Diem HP moi: ";
                                cin>>val;
                                s->setCourseworkMark(val);
                            }
                            else if(opt == 7)
                            {
                                double val;
                                cout<<"Diem NC moi: ";
                                cin>>val;
                                s->setResearchMark(val);
                            }
                            else if(opt == 8)
                            {
                                double val;
                                cout<<"Diem BVLV moi: ";
                                cin>>val;
                                s->setDefenseMark(val);
                            }
                            saveFile();
                            loadingBar();
                            break;
                        }
                    }
                }
            }

            if (!found)
            {
                setColor(12);
                cout << "\nKhong tim thay MSSV nay trong danh sach!\n";
                setColor(7);
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }
        }
    }
    //4.Tim kiem
    void findSV()
    {
        while(true)
        {
            bool found = false;
            int choice = selectMenu("BAN MUON TIM KIEM SINH VIEN NAO?\n", {"Sinh vien dai hoc",
                                                                        "Sinh vien sau sai hoc",
                                                                        "Quay lai menu chinh"});
            if (choice == 3) return;
            if(choice == 1)
            {
                loadFiletoList("UNDERGRADUATE");
                int type = selectMenu("CHON TIEU CHI TIM KIEM (DAI HOC):\n", {"Tim theo MSSV",
                                                                          "Tim theo ho ten",
                                                                          "Tim theo khoang diem CPA",
                                                                          "Tim theo nganh hoc",
                                                                          "Quay lai"});
                if (type == 5) continue;
                system("cls");
                setColor(14);
                cout << "--- NHAP THONG TIN CAN TIM ---\n";
                setColor(7);
                if(type == 1)
                {
                    string x;
                    cout << "Nhap MSSV: ";
                    cin >> x;
                    cout << ">>Sinh vien co MSSV " << x << " la: \n";
                    printHeaderTable("UNDERGRADUATE");
                    for(auto *s: underList)
                    {
                        if(s->getMSSV() == x)
                        {
                            s->display();
                            cout << endl;
                            found = true;
                        }
                    }
                }
                else if(type == 2)
                {
                    cin.ignore();
                    string x;
                    cout << "Nhap ho ten: ";
                    getline(cin, x);
                    cout << ">>Sinh vien co ho ten " << chuanhoaTen(x) << " la: \n";
                    printHeaderTable("UNDERGRADUATE");
                    for(auto *s: underList)
                    {
                        if(s->getName().find(x) != string::npos)   // string::npos : chuoi vo dinh
                        {
                            s->display();
                            cout << endl;
                            found = true;
                        }
                    }
                }
                else if(type == 3)
                {
                    double a,b;
                    cout << "Nhap khoang (a,b): ";
                    cin >> a >> b;
                    cout << ">>Sinh vien co diem CPA trong khoang("  << a << " ," << b << ") la: \n";
                    printHeaderTable("UNDERGRADUATE");
                    for(auto *s: underList)
                    {
                        if(s->getCPA() > a && s->getCPA() < b)
                        {
                            s->display();
                            cout << endl;
                            found = true;
                        }
                    }
                }
                else if(type == 4)
                {
                    string x;
                    cout << "Nhap nganh hoc: ";
                    cin >> x;
                    cout << ">>Sinh vien co MSSV " << chuanhoaNganh(x) << " la: \n";
                    printHeaderTable("UNDERGRADUATE");
                    for(auto *s: underList)
                    {
                        if(s->getCourse() == x)
                        {
                            s->display();
                            cout << endl;
                            found = true;
                        }
                    }
                }
            }

            else
            {
                loadFiletoList("POSTGRADUATE");
                system("cls");
                int type = selectMenu("CHON TIEU CHI TIM KIEM ( SAU DAI HOC):\n", {"Tim theo MSSV",
                                                                                  "Tim theo ho ten",
                                                                                  "Quay lai"
                                                                                });
                if (type == 3) continue;
                system("cls");
                setColor(14);
                cout << "--- NHAP THONG TIN CAN TIM ---\n";
                setColor(7);
                if(type == 1)
                {
                    string x;
                    cout << "Nhap MSSV: ";
                    cin >> x;
                    cout << ">>Sinh vien co MSSV " << x << " la: \n";
                    printHeaderTable("POSTGRADUATE");
                    for(auto *s: postList)
                    {
                        if(s->getMSSV() == x)
                        {
                            s->display();
                            cout << endl;
                            found = true;
                        }
                    }
                }
                else if(type == 2)
                {
                    cin.ignore();
                    string x;
                    cout << "Nhap ho ten: ";
                    getline(cin, x);
                    cout << ">>Sinh vien co ho ten " << chuanhoaTen(x) << " la: \n";
                    printHeaderTable("POSTGRADUATE");
                    for(auto *s: postList)
                    {
                        if(s->getName().find(x) != string::npos)   // string::npos : chuoi vo dinh
                        {
                            s->display();
                            cout << endl;
                            found = true;
                        }
                    }
                }
            }
            if(!found)
            {
                setColor(12); // Mau do
                cout << "\nKhong tim thay sinh vien nao phu hop!\n";
                setColor(7);
            }
             cout << "\nNhan phim bat ky de tiep tuc tim kiem...";
            _getch();
        }
    }

    //5.Thong ke
    void statistics()
    {
        while(true)
        {
            bool found = false;
            int choice = selectMenu("BAN MUON THONG KE?\n", {"Sinh vien dai hoc", "Sinh vien sau dai hoc", "Quay lai menu chinh"});

            if (choice == 3) return;
            system("cls");
            if (choice == 1)
            {
                loadFiletoList("UNDERGRADUATE");
                cout << "\n>>> DANH SACH SINH VIEN DAI HOC HIEN CO:\n";
                if(underList.empty())
                {
                    setColor(12);
                    cout << " >> Danh sach rong!\n";
                    setColor(7);
                }
                else
                {
                    printHeaderTable("UNDERGRADUATE");
                    for (auto s : underList)
                    {
                        s->display();
                        cout << endl;
                    }
                }
                cout << "\n[Nhan phim bat ky de mo menu thong ke nang cao...]";
                _getch();

                int opt = selectMenu("CAC TUY CHON THONG KE (DAI HOC)\n", {"Xem diem CPA trung binh",
                                                                           "Loc sinh vien theo khoang diem CPA (a, b)",
                                                                           "Tim CPA cao nhat",
                                                                           "Quay lai"});

                system("cls");
                setColor(14);
                cout << "\n--- KET QUA THONG KE ---\n";
                setColor(7);
                if(opt == 4)  continue;
                if(opt == 1)
                {
                    double sum = 0;
                    for(auto s: underList)
                    {
                        sum += s->getCPA();
                    }
                    cout << "Diem trung binh CPA la: " <<  sum / underList.size() << "\n";
                    found = true;
                    cout << "Nhan phim bat ky de quay lai...";
                    _getch();
                }

                else if(opt == 2)
                {
                    double a,b;
                    cout << "Nhap khoang (a,b): ";
                    cin >> a >> b;
                    cout << ">>Sinh vien co diem CPA trong doan["  << a << " ," << b << "] la: \n";
                    printHeaderTable("UNDERGRADUATE");
                    for(auto *s: underList)
                    {
                        if(s->getCPA() >= a && s->getCPA() <= b)
                        {
                            s->display();
                            cout << endl;
                        }
                    }
                    found = true;
                    cout << "Nhan phim bat ky de quay lai...";
                    _getch();
                }

                else if(opt == 3)
                {
                    undergraduateStudent* bestCPA = underList[0];
                    cout << " >> Sinh vien co diem CPA cao nhat la:\n";
                    printHeaderTable("UNDERGRADUATE");
                    for(auto s: underList)
                    {
                        if(s->getCPA() > bestCPA->getCPA()) bestCPA = s;
                    }
                    for(auto s: underList)
                    {
                        if(s->getCPA() == bestCPA->getCPA())
                        {
                            s->display();
                            cout << endl;
                        }
                    }
                    found = true;
                    cout << "Nhan phim bat ky de quay lai...";
                    _getch();
                }
            }
        else if(choice == 2)
        {
            loadFiletoList("POSTGRADUATE");
            cout << "\n>>> DANH SACH SINH VIEN SAU DAI HOC HIEN CO:\n";
            if(postList.empty())
            {
                setColor(12);
                cout << " >> Danh sach trong!\n";
                setColor(7);
            }
            else
            {
                printHeaderTable("POSTGRADUATE");
                for (auto s : postList)
                {
                    s->display();
                    cout << endl;
                }
            }

            cout << "\n[Nhan phim bat ky de mo menu thong ke nang cao...]";
            _getch();
            int opt = selectMenu("CAC TUY CHON THONG KE (SAU DAI HOC)\n", {"Sinh vien co tong diem cao nhat",
                                                                         "Sinh vien co diem hoc phan trong khoang(a,b)",
                                                                         "Sinh vien co diem nghien cuu trong khoang(a,b)",
                                                                         "Sinh vien co diem bao ve luan van trong khoang (a,b)",
                                                                         "Sinh vien co diem hoc phan cao nhat",
                                                                         "Sinh vien co diem hoc nghien cuu cao nhat",
                                                                         "Sinh vien co diem hoc bao ve luan van cao nhat",
                                                                         "Quay lai"});
                if(opt == 8)  continue;
                system("cls");
                setColor(14);
                cout << "--- KET QUA THONG KE ---\n\n";
                setColor(7);
            if (opt == 1)
            {
                double maxScore = postList[0]->getCourseworkMark()+ postList[0]->getResearchMark()+ postList[0]->getDefenseMark();
                cout << ">> Sinh vien co tong diem cao nhat la:\n";
                printHeaderTable("POSTGRADUATE");
                for (auto s : postList)
                {
                    double total = s->getCourseworkMark()
                    + s->getResearchMark()
                    + s->getDefenseMark();
                    if (total > maxScore)
                    {
                        maxScore = total;
                    }
                }
                for (auto s : postList)
                {
                    double total = s->getCourseworkMark()
                                   + s->getResearchMark()
                                   + s->getDefenseMark();
                    if (total == maxScore)
                    {
                        s->display();
                        cout << '\n';
                    }
                }
                found = true;
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }

            else if(opt == 2)
            {
                double a,b;
                cout << "Nhap khoang (a,b): ";
                cin >> a >> b;
                cout << ">>Sinh vien co diem hoc phan trong doan["  << a << " ," << b << "] la: \n";
                printHeaderTable("POSTGRADUATE");
                for(auto *s: postList)
                {
                    if(s->getCourseworkMark() >= a && s->getCourseworkMark() <= b)
                    {
                        s->display();
                        cout << endl;

                    }
                }
                found = true;
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }
            else if(opt == 3)
            {
                double a,b;
                cout << "Nhap khoang (a,b): ";
                cin >> a >> b;
                cout << ">>Sinh vien co diem nghien cuu trong doan["  << a << " ," << b << "] la: \n";
                printHeaderTable("POSTGRADUATE");
                for(auto *s: postList)
                {
                    if(s->getResearchMark() >= a && s->getResearchMark() <= b)
                    {
                        s->display();
                        cout << endl;
                    }
                }
                found = true;
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }
            else if(opt == 4)
            {
                double a,b;
                cout << "Nhap khoang (a,b): ";
                cin >> a >> b;
                cout << ">>Sinh vien co diem bao ve luan van trong doan["  << a << " ," << b << "] la: \n";
                printHeaderTable("POSTGRADUATE");
                for(auto *s: postList)
                {
                    if(s->getDefenseMark() >= a && s->getDefenseMark() <= b)
                    {
                        s->display();
                        cout << endl;
                    }
                }
                found = true;
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }
            else if(opt == 5)
            {
                postgraduateStudent* bestCourseworkMark = postList[0];
                cout << ">>Sinh vien co diem hoc phan cao nhat (" << bestCourseworkMark->getCourseworkMark() << ") la:\n";
                printHeaderTable("POSTGRADUATE");
                for(auto s : postList)
                {
                    if(s->getCourseworkMark() > bestCourseworkMark->getCourseworkMark())
                    {
                        bestCourseworkMark = s;
                    }
                }
                for(auto s : postList)
                {
                    if(s->getCourseworkMark() == bestCourseworkMark->getCourseworkMark() )
                    {
                        s->display();
                        cout << endl;
                    }
                }
                found = true;
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }
            else if(opt == 6)
            {
                postgraduateStudent* bestResearchMark = postList[0];
                cout << ">>Sinh vien co diem nghien cuu cao nhat (" << bestResearchMark->getResearchMark() << ") la:\n";
                printHeaderTable("POSTGRADUATE");
                for(auto s : postList)
                {
                    if(s->getResearchMark() > bestResearchMark->getResearchMark())
                    {
                        bestResearchMark = s;
                    }
                }
                for(auto s : postList)
                {
                    if(s->getResearchMark() == bestResearchMark->getResearchMark() )
                    {
                        s->display();
                        cout << endl;
                    }
                }
                found = true;
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }
            else if(opt == 7)
            {
                postgraduateStudent* bestDefenseMark = postList[0];
                cout << ">>Sinh vien co diem bao ve luan van cao nhat (" << bestDefenseMark->getDefenseMark() << ") la:\n";
                printHeaderTable("POSTGRADUATE");
                for(auto s : postList)
                {
                    if(s->getDefenseMark() > bestDefenseMark->getDefenseMark())
                    {
                        bestDefenseMark = s;
                    }
                }
                for(auto s : postList)
                {
                    if(s->getDefenseMark() == bestDefenseMark->getDefenseMark() )
                    {
                        s->display();
                        cout << endl;
                    }
                }
                found = true;
                cout << "Nhan phim bat ky de quay lai...";
                _getch();
            }
        }
        if (!found)
        {
            setColor(12);
            cout << "\nKhong tim thay thong tin!\n";
            setColor(7);
            cout << "Nhan phim bat ky de quay lai...";
            _getch();
        }
    }
    }
};

struct Account{ string username, password, role; };

class loginSystem
{
private:
    vector<Account> accounts;
    string inputPassword()
    {
        string password = "";
        char x;
        while(true)
        {
            x = _getch(); // lÆ°u Ã½
            if(x == ENTER)
            {
                cout << endl;
                break;
            }
            else if(x == BACKSPACE)
            {
                if(!password.empty())
                {
                    password.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                password.push_back(x);
                cout << "*";
            }
        }
        return password;
    }

public:
    loginSystem()
    {
        accounts.push_back({"Doan Phuoc Long", "202514239", "ADMIN"});
        accounts.push_back({"Nguyen Van Duy", "202514094", "USER"});
        accounts.push_back({"Nguyen Minh Phuong", "202514334", "USER"});
    }
    string login()
    {
        string NAME, PASS;
        int attempt = 0;
        while(attempt < 3)
        {
            cout << "\n=========DANG NHAP HE THONG=========\n";
            cout << "Ho ten: ";
            getline(cin, NAME);
            cout << "Mat khau: ";
            PASS = inputPassword();
            for(auto acc: accounts)
            {
                if(acc.username == NAME && acc.password == PASS)
                {
                    cout << "Dang nhap thanh cong! Xin chao " << acc.role << ".\n";
                    Sleep(1000);
                    return acc.role;
                }
            }
            attempt++;
            cout << "Sai tai khoan hoac mat khau!\n";
            cout << "Ban con " << (3 - attempt) << " lan nhap!\n\n";
        }
        return "none";
    }

};


int main()
{
    loginSystem login;
    manageStudent manager;

    string role = login.login();
    if (role == "none")
    {
        cout << "Dang nhap that bai. Thoat chuong trinh!\n";
        return 0;
    }
    if (role == "ADMIN")
    {
        while (true)
        {
            vector<string> mainOpt = {"Them sinh vien",
                                      "Xoa sinh vien",
                                      "Sua thong tin sinh vien",
                                      "Tim kiem sinh vien",
                                      "Thong ke chi tiet sinh vien",
                                      "Thoat"};
            int choice = selectMenu("\n========= MENU ADMIN =========\n", mainOpt);
            switch (choice)
            {
            case 6:
                cout << "Thoat chuong trinh!\n";
                return 0;
            case 1:
                manager.addByMSSV();
                break;
            case 2:
                manager.deleteByMSV();
                break;
            case 3:
                manager.editInfo();
                break;
            case 4:
                manager.findSV();
                break;
            case 5:
                manager.statistics();
                break;
            default:
                cout << "Lua chon khong hop le!\n";
            }
        }
    }
    else if (role == "USER")
    {
        while (true)
        {
            vector<string> mainOpt = {"Tim kiem sinh vien",
                                      "Xem thong ke chi tiet sinh vien",
                                      "Thoat"};
            int choice = selectMenu("\n========= MENU USER =========\n", mainOpt);
            switch (choice)
            {
            case 3:
                cout << "Thoat chuong trinh!\n";
                return 0;
            case 1:
                manager.findSV();
                break;
            case 2:
                manager.statistics();
                break;
            default:
                cout << "Lua chon khong hop le!\n";
            }
        }
    }
    else
    {
        cout << "Role khong hop le!\n";
        return 0;
    }

    return 0;
}
