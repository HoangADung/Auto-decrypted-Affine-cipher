#include <bits/stdc++.h>
using namespace std;
class Word{
    private:
    	string word;
    public:
    	Word();
    	Word(string word);
    	string getWord();
    	void setword(string newword);
};

class BinarySearchTree{
    private:
        struct tree_node{
           tree_node* left;
           tree_node* right;
           Word data;
        };
        tree_node* root;
    public:
        BinarySearchTree(){
           root = NULL;
        }
        bool isEmpty() const {return root==NULL;}
        void inorder(tree_node*);
        void insert(Word);
        void search(string key);
        bool search1(string key);
};
Word::Word(){}
Word::Word(string newword){
    word = newword;
}
string Word::getWord() {
    return word;
}
void Word::setword(string newword){
    word = newword;
}
void BinarySearchTree::insert(Word p){
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = p;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    // is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data.getWord() > curr->data.getWord()) curr = curr->right;
            else curr = curr->left;
        }
        if(t->data.getWord() < parent->data.getWord())
           parent->left = t;
        else
           parent->right = t;
    }
}
void BinarySearchTree::inorder(tree_node* p){

    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<"  "<<p->data.getWord()<<endl;
        if(p->right) inorder(p->right);
    }
    else return;
}
bool BinarySearchTree::search1(string key)
{
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data.getWord() == key)
         {
         	return true;
            break;
         }
         else
         {
             parent = curr;
             if(key>curr->data.getWord()) curr = curr->right;
             else curr = curr->left;
         }
    }
    return false;
}
void BinarySearchTree::search(string key){
    bool found = false;
    //int count=0;
    if(isEmpty()){
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data.getWord() == key)
         {
            found = true;
            cout << "Tu ban dang muon tim co the la: " << curr->data.getWord() << endl;
            break;
         }
         else
         {
             parent = curr;
             if(key>curr->data.getWord()) curr = curr->right;
             else curr = curr->left;
         }
    }
    /*if(!found){
        continue;
    }*/
}
string binarySearch(string dictionary[], int l, int r, string x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
    	if (dictionary[mid] == x) return dictionary[mid];
    	if (dictionary[mid] > x) return binarySearch(dictionary, l, mid - 1, x);
    return binarySearch(dictionary, mid + 1, r, x);
	}
	return "notherebro";
}
void fillTree(string *dictionary){
    ifstream file("dictionary.txt",ios::app);
    if(!file) {
        cout<<" Error opening file. " << endl;
    }
    int i=0;
    string word;
    while(file >> word ){
    	dictionary[i]=word;
    	i++;
    }
    file.close();
}
void fillFile(string word){
    ofstream file("dictionary.txt", ios::app);
	if(!file) {
		cout<<" Error opening file. " << endl;
    }
	file<<word<<endl;
	file.close();
}
int UocChungLonNhat(int a, int b){
	if (a==b) return a;
	if (a<b) return UocChungLonNhat(a,b-a);
		else return UocChungLonNhat(b,a-b);
}
int SoThuTu(char KyTu){
	if((KyTu>='a')&&(KyTu<='z')) return KyTu-97;
	if((KyTu>='A')&&(KyTu<='Z')) return KyTu-65;
}
char BangChuCai(int So){
	if((So>=0)&&(So<=25)) return So+65;
}
int NghichDaoNhan(int So, int Mod){
	int u = So, v = Mod,x,x1=1, x2=0,q,r;
	while(u!=1){
		q=v/u; r=v-q*u; x=x2-q*x1;
		v=u;u=r;x2=x1;x1=x;
	}
	if ((x1%Mod)>0) return (x1%Mod);
		else return (x1%Mod+Mod);
}
int main(){
	cout<<"AFFINE CIPHER DECRYPTION AND ENCRYPTION"<<endl<<"--------------------------------------------------"<<endl;
	int i,j,m,p,count,check=0,choice,k1,k2;
	string VanBanGoc,VanBanMaHoa,x;
	string dictionary[58110];
	int n = sizeof(dictionary) / sizeof(dictionary[0]);
	while(1){
		cout<<"Nhap vao lua chon: "<<endl<<"1.Ma hoa"<<'\t'<<"2.Giai ma"<<'\t'<<"3.Pha khoa"<<'\t'<<"4.Tra tu thu cong"<<'\t'<<"0.Ket thuc chuong trinh"<<endl; cin>>choice;
		switch(choice){
			case 0:
				return 0;
			case 1:
				while(check==0){
					cout<<"Nhap vao bo ma khoa (k1,k2): "<<endl;
					cout<<"k1 = ";cin>>k1; cout<<"k2 = "; cin>>k2;
					if(UocChungLonNhat(k1,26)!=1){
						cout<<"Yeu cau nhap lai. k1 phai thuoc Z26 va nguyen to cung nhau voi 26 !!!"<<endl<<"--------------------------------------------------"<<endl;
					}
				else check=1;
				}
				check=0;i=0;
				fflush(stdin);
				VanBanGoc.resize(9999);
				VanBanMaHoa.resize(9999);
				cout<<"Nhap vao van ban goc: "; 
				getline(cin,VanBanGoc);
				cout<<"Van ban da duoc ma hoa: ";
				for (i=0;VanBanGoc[i]!='\0';i++){
					if ((VanBanGoc[i]<'A')||((VanBanGoc[i]>'Z')&&(VanBanGoc[i]<'a'))||(VanBanGoc[i]>'z')) VanBanMaHoa[i]=VanBanGoc[i];
						else VanBanMaHoa[i]=BangChuCai((k1*SoThuTu(VanBanGoc[i])+k2)%26);
				}
				VanBanGoc.resize(i);
				VanBanMaHoa.resize(i);
				cout<<VanBanMaHoa;
				cout<<endl<<"--------------------------------------------------"<<endl;
				break;
			case 2:
				while(check==0){
					cout<<"Nhap vao bo ma khoa (k1,k2): "<<endl;
					cout<<"k1 = ";cin>>k1; cout<<"k2 = "; cin>>k2;
					if(UocChungLonNhat(k1,26)!=1){
						cout<<"Yeu cau nhap lai. k1 phai thuoc Z26 va nguyen to cung nhau voi 26 !!!"<<endl<<"--------------------------------------------------"<<endl;
					}
				else check=1;
				}
				check=0;i=0;
				fflush(stdin);
				VanBanGoc.resize(9999);
				VanBanMaHoa.resize(9999);
				cout<<"Nhap vao van ban can giai ma: "; 
				getline(cin,VanBanMaHoa);
				cout<<"Van ban da duoc giai ma: ";
				for(i=0;VanBanMaHoa[i]!='\0';i++){
					if ((VanBanMaHoa[i]<'A')||((VanBanMaHoa[i]>'Z')&&(VanBanMaHoa[i]<'a'))||(VanBanMaHoa[i]>'z')) VanBanGoc[i]=VanBanMaHoa[i];
						else {
							m=((SoThuTu(VanBanMaHoa[i])-k2)*NghichDaoNhan(k1,26))%26;
							if (m<0) m=m+26;
							VanBanGoc[i]=BangChuCai(m);
					}
				}
				VanBanGoc.resize(i);
				VanBanMaHoa.resize(i);
				cout<<VanBanGoc;
				cout<<endl<<"--------------------------------------------------"<<endl;
				break;
			case 3:
				fflush(stdin);	
				VanBanGoc.resize(9999);
				VanBanMaHoa.resize(9999);
				x.resize(999);
				cout<<"Nhap vao van ban can pha khoa: ";
				getline(cin,VanBanMaHoa);
    			fillTree(dictionary);
				i=0;j=0;
			    while (VanBanMaHoa[j]!='\0'){
			    	count=0;
			        if (((VanBanMaHoa[j]>='a')&&(VanBanMaHoa[j]<='z'))||((VanBanMaHoa[j]>='A')&&(VanBanMaHoa[j]<='Z'))) {
			            x[i]=VanBanMaHoa[j];
						i++;		            
			        }
					else {
						x.resize(i);
		    			for(k1=1;k1<26;k1++){
		    				if(UocChungLonNhat(k1,26)!=1){
								continue;
							}
							for(k2=0;k2<26;k2++){
								for(p=0;x[p]!='\0';p++){
									m=((SoThuTu(x[p])-k2)*NghichDaoNhan(k1,26))%26;
									if (m<0) m=m+26;
									VanBanGoc[p]=BangChuCai(m);
								}
								VanBanGoc.resize(p);
								p=0; //cout<<VanBanGoc<<" ";
								string result=binarySearch(dictionary, 0, n - 1, VanBanGoc);
								if (result!="notherebro") {
									cout<<VanBanGoc<<" ";
									count++;
								}
							}
						}
						VanBanGoc.resize(999); x.resize(999);
						if (count==0) cout<<"?"<<" ";
						cout<<endl;
						i=0;
			        }
			        j++;
			    }
			    x.resize(i);
		    	for(k1=1;k1<26;k1++){
		    	if(UocChungLonNhat(k1,26)!=1){
					continue;
				}
					for(k2=0;k2<26;k2++){
						for(p=0;x[p]!='\0';p++){
							m=((SoThuTu(x[p])-k2)*NghichDaoNhan(k1,26))%26;
							if (m<0) m=m+26;
							VanBanGoc[p]=BangChuCai(m);
						}
						VanBanGoc.resize(p);
						p=0; //cout<<VanBanGoc<<" ";
						string result=binarySearch(dictionary, 0, n - 1, VanBanGoc);
						if (result!="notherebro") {
							cout<<VanBanGoc<<" ";
							count++;
						}
					}
				}
				VanBanGoc.resize(9999); x.resize(9999);
				if (count==0) cout<<"?"<<" ";
				i=0;
			    j++;
				cout<<endl<<"--------------------------------------------------"<<endl;
				break;
			case 4:
				fflush(stdin);	
				VanBanGoc.resize(9999);
				VanBanMaHoa.resize(9999);
				cout<<"Nhap vao van ban can pha khoa: ";
				getline(cin,VanBanMaHoa);
    			fillTree(dictionary);
    			count=0;
    			cout<<"Hien tat ca nhung tu co the: "<<endl;
    			for(k1=1;k1<26;k1++){
    				if(UocChungLonNhat(k1,26)!=1){
						continue;
					}
					for(k2=0;k2<26;k2++){
						for(i=0;VanBanMaHoa[i]!='\0';i++){
							if ((VanBanMaHoa[i]<'A')||((VanBanMaHoa[i]>'Z')&&(VanBanMaHoa[i]<'a'))||(VanBanMaHoa[i]>'z')) VanBanGoc[i]=VanBanMaHoa[i];
								else {
									m=((SoThuTu(VanBanMaHoa[i])-k2)*NghichDaoNhan(k1,26))%26;
									if (m<0) m=m+26;
									VanBanGoc[i]=BangChuCai(m);
								}
						}
						VanBanGoc.resize(i);
						VanBanMaHoa.resize(i);
						i=0;count++;
						cout<<VanBanGoc<<" ";	
					}
				}
				cout<<endl<<"--------------------------------------------------"<<endl;
				break;			
		}
	}
}
