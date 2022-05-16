#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <cstring>

using namespace std;
#define BUFF_SIZE 128
typedef struct A{
    int id;
    string name;
    int age;
    float score;
    struct A *link;
}list_node;

class SList{
    private:
    list_node *head;

    public:
    void Print();
    void Insert();
    void Delete();
    bool Retrieve();
    void Sort(list_node *head);
    void Set();
};
string selectMenu();
void Menu();
int main(){
    string menu;
    SList *s1 = new SList();
    s1->Set();
    while(1){
        
        menu = selectMenu();
        if(menu == "A"){
            s1->Insert();
            continue;
        }
        if(menu == "D"){
            s1->Delete();
            continue;
        }
        if(menu == "R"){
            s1->Retrieve();
            continue;
        }
        if(menu == "P"){
            s1->Print();
            continue;
        }
        if(menu == "Q"){
            break;
        }
    }
}
string selectMenu(){
    string a;
    cout << endl;
    cout << "*********** MENU ****************" << endl;
    cout << "A : Add new data" << endl;
    cout << "D : Delete Data" << endl;
    cout << "R : Retrieve data" << endl;
    cout << "P : Print list" << endl;
    cout << "Q : Quit" << endl;
    cout << "Choose menu : ";
    cin >> a;
    return a;
}
void Menu(){
    cout << endl;
    cout << "*********** MENU ****************" << endl;
    cout << "A : Add new data" << endl;
    cout << "D : Delete Data" << endl;
    cout << "R : Retrieve data" << endl;
    cout << "P : Print list" << endl;
    cout << "Q : Quit" << endl;
}
void SList::Insert(){
    
    int b,c;
    string a;
    float d;
    
    cout << "==> Type student name : ";
    cin >> a ;
    cout << "==> Type student id : ";
    cin >> b;
    cout << "==> Type age of student : ";
    cin >> c;
    cout << "==> Type score : ";
    cin >> d;
    cout << endl;
    list_node * new_node = new list_node;
    new_node-> id = b;
    new_node-> name = a;
    new_node-> age = c;
    new_node-> score = d;
    new_node->link = head;
    head = new_node;
    
    Sort(new_node);
    Menu();
    cout << a <<"'s record is added" << endl;;

}
void SList::Delete(){
    list_node* prev;//이전노드
    list_node* curr = head;//처음노드를 현재꺼에 지정함.
    cout << "==> Type student id :";
    int d;
    cin >> d;
    while(curr->link != NULL && curr->id != d){
        prev = curr;
        curr = curr->link;
    }
    if(curr != NULL){
        if(curr == head) head = curr->link;//쓰는 이유는 위의 반복문 거치지않았다면 prev는 아무것도 포인팅하지 않음.
        else{
            prev->link = curr->link;
            } 
        cout << curr->name << "'s record is deleted." << endl;
        delete curr;
    }
    //else target is NULL
}   
bool SList::Retrieve(){
    list_node *cur = NULL;
    cout << "==> Type student id : " ;
    int temp;
    cin >> temp;
    for(cur = head; cur != NULL; cur = cur->link){
        if(cur->id == temp)
        break;
    }//if data !=NULL, found
    if(cur != NULL){
        cout << cur->name << "'s age is " << cur->age << " and score is " << cur->score << endl;
    }
    else{
        cout << "Illegal id number" << endl;
    }
}
void SList::Print(){
    list_node *cur = NULL;
    cout <<"id_number    " << "   name      " << "      age    " << "      score " << endl;
    for(cur = head; cur != NULL; cur = cur->link){
        cout << cur->id;
        cout.width(15);
        cout << cur->name;
        cout.width(15);
        cout << cur->age;
        cout.width(15);
        cout << cur->score ;
    }
} 

void SList::Sort(list_node *head){
    list_node *curr;
    list_node *next;
    int b,c;
    string a;
    float d;

    for(curr = head; curr != NULL; curr = curr->link){
        for(next = curr->link; next != NULL; next = next->link){
            if(curr->id > next->id){
                b = next->id;
                a = next->name;
                c = next->age;
                d = next->score;
                next->id = curr->id;
                next->name = curr->name;
                next->age = curr->age;
                next->score = curr->score;
                curr->id = b;
                curr->name = a;
                curr->age = c;
                curr->score = d;

            }
            
        }
    }

}
void SList::Set(){
    FILE * ifile;
    ifile = fopen("hw4.txt","r");
    fseek(ifile, SEEK_SET, 0);
    
    list_node * file_node = new list_node;
    char buffer[BUFF_SIZE];
    
    int count = 0;
    while(!ifile){ 
        
        //getline(ifile,buffer,'\n');
        count = 0;
        fgets(buffer, BUFF_SIZE,ifile);
        
        
        
        char *ptr = strtok(buffer, " ");    //첫번째 strtok 사용.
        file_node->id = atoi(ptr);
        
        while (ptr != NULL)              //ptr이 NULL일때까지 (= strtok 함수가 NULL을 반환할때까지)
        {
            ++count;
            if(count == 2){
                ptr = strtok(NULL, " "); 
                file_node->age = atoi(ptr);
                
                continue;
            }
            if(count == 3){
                ptr = strtok(NULL, " ");
                file_node->score = atof(ptr);
                break;
            }
                //자른 문자 출력
            ptr = strtok(NULL, " ");     //자른 문자 다음부터 구분자 또 찾기
            file_node-> name = ptr;
        }
        file_node->link = head;
        head = file_node;
        Sort(file_node);
    }


}

