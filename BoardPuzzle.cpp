#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void SetColor(int);
enum move{LEFT=0,RIGHT,UP,DOWN};
class Guess
{   private:
	//variables
	string board[4][4];
	int rem_row;
	int rem_col;
	int max_score;	
	std::vector<string>values={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16"};
	public:
		Guess()
		{
				ifstream file1;
				file1.open("high_score",ios::binary|ios::in);
				file1>>max_score;
				file1.close();
			int rand_row=rand()%4;
			int rand_col=rand()%4;
			 rem_row=rand_row;
			 rem_col=rand_col;
			board[rand_row][rand_col]="00";
			int store=rem_row%rand();
			int store1=store;
			bool ok=false;
			for(int i=0;i<4;i++)
			{for(int j=0;j<4;j++)
			{	
				if(i==rem_row&&j==rem_col)
				continue;
				board[i][j]=values[store];
				values[store++]="!";
				if(store1!=0&&store==(values.size()-1))
				store=0;
				if(store==(store1)){
				ok=true;
				break ;
							
			}
			} 
			if(ok==true)
			break;
		}
		values.clear();
		values={"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","00"};
		}
		virtual ~Guess()
		{
			cout<<"   [#] !!!!!!GAME OVER!!!!!"<<endl;
		}
		void draw_board()
		{ aa: int ma=rand();
		if(ma>8||ma==4)
		goto aa;
			cout<<"        ___________________________________________________________  "<<endl;
			for(int i=0;i<4;i++){
				cout<<endl;
			    for(int j=0;j<4;j++)
			    {
					SetColor(i+j+ma);
					if(i==0&&j==0)
					SetColor(rand()%8+1);
					else if(i==rem_row&&j==rem_col)
					SetColor(14);
				cout<<"       |     "<<board[i][j];
			    if(board[i][j]=="00 ")
			    {
			    	cout<<" ";
				}
				}
			    cout<<"       |  "<<endl<<endl;
			    
		                        }
			cout<<"       |___________________________________________________________|  "<<endl<<endl<<endl<<"                         [#] HIGH SCORE TILL NOW [#] :- "<<max_score<<endl<<endl;
		}
		void update_board(enum move var);
		bool checking(enum move var);
		bool GameOver();
		void banner();
};
void Guess::update_board(enum move var)
{	bool check=checking(var);
if(check==true){
	string temp1="";
	if(var==LEFT)
	{
		int new_col=this->rem_col-1;
		temp1=board[this->rem_row][new_col];
		board[this->rem_row][new_col]="00";
		board[this->rem_row][this->rem_col]=temp1;
		this->rem_col=new_col;
	}
	else if(var==RIGHT)
	{
		int new_col=this->rem_col+1;
		temp1=board[this->rem_row][new_col];
		board[this->rem_row][new_col]="00";
		board[this->rem_row][this->rem_col]=temp1;
		this->rem_col=new_col;
	}
	else if(var==UP)
	{
		int new_row=this->rem_row-1;
		temp1=board[new_row][rem_col];
		board[new_row][rem_col]="00";
		board[this->rem_row][this->rem_col]=temp1;
		this->rem_row=new_row;
	}
		else if(var==DOWN)
	{
		int new_row=this->rem_row+1;
		temp1=board[new_row][rem_col];
		board[new_row][rem_col]="00";
		board[this->rem_row][this->rem_col]=temp1;
		this->rem_row=new_row;
	}
}
}
bool Guess::checking(enum move var)
{
if(var==LEFT)
	{
		int new_col=this->rem_col-1;
		if(new_col>3||new_col<0)
		{
			cout<<"[#] ** YOU CAN ONLY MOVE INSIDE BLOCK AND WILL NOT BE ABLE TO GET OUTSIDE ** [#]"<<endl;
			return false;
		}
	}
	else if(var==RIGHT)
	{
		int new_col=this->rem_col+1;
		if(new_col>3||new_col<0)
		{
			cout<<"[#] ** YOU CAN ONLY MOVE INSIDE BLOCK AND WILL NOT BE ABLE TO GET OUTSIDE ** [#]"<<endl;
			return false;
		}
	}
	else if(var==UP)
	{
		int new_row=this->rem_row-1;
		if(new_row>3||new_row<0)
		{
			cout<<"[#] ** YOU CAN ONLY MOVE INSIDE BLOCK AND WILL NOT BE ABLE TO GET OUTSIDE ** [#]"<<endl;
			return false;
		}
	}
		else if(var==DOWN)
	{
		int new_row=this->rem_row+1;
		if(new_row>3||new_row<0)
		{
			cout<<"[#] ** YOU CAN ONLY MOVE INSIDE BLOCK AND WILL NOT BE ABLE TO GET OUTSIDE ** [#]"<<endl;
			return false;
		}
	}
	return true;
}
void Guess::banner()
{
  	cout<<"# CREATED.......BY..... "<<endl;
cout<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<"		s	ll      rr   rr     "<<endl;
cout<<"		sssss	ll	rrrrrrr	    "<<endl;
cout<<"		    s   ll	rr rr       "<<endl;
cout<<"		sssss	llllll  rr   rr     "<<endl;
cout<<endl<<endl;
 cout<<"[*] FOR ANY QUERY CONTACT AT \"SURJEETRAJPUT433@GMAIL.COM\" [*]"<<endl;
cout<<endl<<endl;

}
bool Guess::GameOver()
{	int k=0;

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j]!=values[k])
			{
				return false;
			}
		k++;
		}
	}
	return true;
}
void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
}
int main()
{ 
Guess* guess=new Guess();//initialising the constructure of the Guess class by pointer variable
enum move var;
int chances=250;
static int change_color=0;
change_color++;
guess->banner();
SetColor(change_color);
cout<<"[#] PRESS ENTER TO START THE GAME [#]\n";
cout<<endl<<"                              [#]  !!!! INSTRUCTIONS !!!! [#]"<<endl;
cout<<"\n[#] ARRANGE GIVEN NUMBER PUZZLE IN THE INCREASING ORDER OF THEIR VALUE\n\n[#] YOU WILL ONLY BE ABLE TO WIN THIS GAME IF YOU ARRANGE NUMBER IN INCREASING ORDER\n\n[#] WE ALSO PROVIDED YOU THE OPTION BY WHICH YOUR ALL STEPS SAVE IN A FILE AND AFTER FINISHING THE GAME YOU CAN ANALYSE     YOUR STEPS [#]\n\n[#] IMPORTANT NOTICE: YOU CAN ONLY CONTROL THE 00 DAT AND AFTER SOLVING PUZZLE 00 MUST BE AT END \n\n"<<"[#] LIKE [#] \n";
cout<<"\n01 02 03 04\n";
cout<<"05 06 07 08\n";
cout<<"09 10 11 12\n";
cout<<"13 14 15 00";
cin.get();
 system("cls");
guess->draw_board();//drwing the board
bool game_over=false;
int val=1;
SetColor(val++);
while(true){
val=((rand())%9+1);
SetColor(val++);
if(chances<=0)
break;
cout<<endl<<"[#] ** NUMBER OF CHANCE LEFT TO SOLVE THIS PUZZLE ** [#] : - "<<chances<<endl;

aa:
cout<<"\n[#]W. UP\n[#]S. DOWN\n[#]A. LEFT\n[#]D. RIGHT\n\n[#] ** PRESS 0 TO EXIT THE GAME ** [#]\n";
char option;
string s;
cin>>s;
//cin.ignore();
option=(char)s[0];//copying only the first value of string to character
system("cls");
if(option=='0'){

chances=0;
break;

}
if(option=='W'||option=='w')
var=UP;

else if(option=='S'||option=='s')
var=DOWN;

else if(option=='A'||option=='a')
var=LEFT;

else if(option=='D'||option=='d') 
var=RIGHT;

else
{
guess->draw_board();
cout<<"\n\a[#]** CHOOSE ONLY GIVEN OPTIONS EITHER IT WILL NOT MOVE  **[#]\n" ;
goto aa;
}
ofstream f;
f.open("steps",ios::app|ios::out);
f<<option<<" ";
f.close();
guess->update_board(var);

guess->draw_board();

game_over=guess->GameOver();
if(game_over==true)
{
break;
}
chances--;			
}
system("cls");
guess->banner();

if(chances>0)
{	SetColor(10);
	cout<<"[#] YOU WIN THIS GAME AND NUMBER OF CHANCES LEFT :- "<<chances<<" [#]"<<endl<<endl;
	ifstream file1;
	file1.open("high_score",ios::binary|ios::in);
	int max_score=0;
	file1>>max_score;
	file1.close();
	if(chances>max_score){
	fstream file;
	file.open("high_score",ios::binary|ios::out);
	file<<chances;
	file.close();
}
}
SetColor(12);
delete guess;

return 0;
}
