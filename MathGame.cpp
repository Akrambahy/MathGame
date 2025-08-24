#include <iostream>
#include<ctime>


using namespace std;


//Enums


enum enQuestionsLevel {Esay =1 ,Mid =2 ,Hard =3 , Mix =4};

enum enOperationsType{ Add=1 , Sub =2 ,Mul =3 , Div =4};

//Structs


struct stGameInfo{
short NumberOfQustions=0;
int UserAnswer;
int RightAnswer;
enQuestionsLevel QuestionsLevel;
enOperationsType OperationsType;
};

struct stGameResults{
short RightAnswers=0; // Total Of Right Answers For User
short WrongAnswers=0; // Total Of Wrong Answers For User
bool FinalResult ;// Pass Or Fail
};

// Functions


int RandomNumber(int From, int To) //Function to generate a random number
    {

        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

short GetNumberOfQuestions() // To Ask User How Many Questions Want
{
short NumberOfQuestions;

cout<<"Pleas Enter Number Of Questions You Want ?\n";

cin>>NumberOfQuestions;

return NumberOfQuestions;
}


enQuestionsLevel GetQuestionsLevel() // to Ask User About the Level Of Questions And Return it
{
short LevelNumber;

cout<<"Pleas Choose Level Of Questions You Want : \n";

cout <<"[1] : Esay\n";
cout <<"[2] : Mid\n";
cout <<"[3] : Hard\n";
cout <<"[4] : Mix\n";
cin>>LevelNumber;

return enQuestionsLevel(LevelNumber);
};

enOperationsType GetOperationsType() // to Ask User About the Operation Type Of Questions And Return it
{

short OperationTypeNumber;

cout<<"Pleas Choose OperationType Of Questions You Want : \n";

cout <<"[1] : Add\n";
cout <<"[2] : Sub\n";
cout <<"[3] : Mul\n";
cout <<"[4] : Div\n";
cin>>OperationTypeNumber;

return enOperationsType(OperationTypeNumber);

}

int GenerateEsayNumber(){
return RandomNumber(1,20) ;
};

int GenerateMidNumber(){
return RandomNumber(20,100) ;
};

int GenerateHardNumber(){
return RandomNumber(100,500) ;
};

int GenerateMixNumber(){
return RandomNumber(1,500) ;
};

void GenerateQuestion(int &RightAnswer  ,enQuestionsLevel QuestionsLevel ,enOperationsType OperationsType )// to Take  And Print Add Question
{

int Number1;
int Number2;

char Operation;


switch (QuestionsLevel)
{
case enQuestionsLevel::Esay :
    Number1=GenerateEsayNumber();
    Number2=GenerateEsayNumber();

    break;
case enQuestionsLevel::Mid :
    Number1=GenerateMidNumber();
    Number2=GenerateMidNumber();

    break;
case enQuestionsLevel::Hard :
    Number1=GenerateHardNumber();
    Number2=GenerateHardNumber();

    break;
case enQuestionsLevel::Mix :
    Number1=GenerateMixNumber();
    Number2=GenerateMixNumber();

    break;

default:
    Number1=GenerateMidNumber();
    Number2=GenerateMidNumber();
}
switch (OperationsType)
{
case enOperationsType::Add :
    Operation='+';
    RightAnswer=Number1+Number2;
    break;

case enOperationsType::Sub :
    Operation='-';
    RightAnswer=Number1-Number2;
    break;

case enOperationsType::Mul :
    Operation='*';
    RightAnswer=Number1*Number2;
    break;
case enOperationsType::Div :
    Operation='/';
    RightAnswer=Number1/Number2;
    break;

default:
Operation='+';
RightAnswer=Number1+Number2;}

cout<<Number1<<Operation<<Number2<<endl;

}

void AnswerIsRight()// Green Screen Light
{
        cout << "\033[32mCorrect!\033[0m\n";
}

void AnswerIsWronge() // Red Screen Light And Rang Sound
{
    cout<<"\033[31mWrong!\033[0m\n";
}

void PassMassage() // Print Pass Massage If User Pass Quiz
{
        cout << "\n\033[32mYou Are Pass\033[0m\n";


}



void FailMassage() // Print Fail Massage If User Fail Quiz
{
       cout<<"\n\033[31mYou Are Fail\033[0m\n";


}



void GamePlay() // To Start And Play Game
{
short UserRightAnswers=0;

stGameInfo GameInfo;
stGameResults GameResults;

GameInfo.NumberOfQustions=GetNumberOfQuestions();
GameInfo.QuestionsLevel=GetQuestionsLevel();
GameInfo.OperationsType=GetOperationsType();

for(int i=1 ; i<=GameInfo.NumberOfQustions;i++){

GenerateQuestion(GameInfo.RightAnswer , GameInfo.QuestionsLevel , GameInfo.OperationsType);
cin>>GameInfo.UserAnswer;
if(GameInfo.UserAnswer==GameInfo.RightAnswer){
AnswerIsRight();
GameResults.RightAnswers++ ;}
else{
AnswerIsWronge();
 GameResults.WrongAnswers++;
}
}

(GameResults.RightAnswers>=GameResults.WrongAnswers) ?GameResults.FinalResult=true  : GameResults.FinalResult=false;

(GameResults.FinalResult==true) ? PassMassage():FailMassage();

}


int main(){
srand((unsigned)time(NULL));

GamePlay();

}

