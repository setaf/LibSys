#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*the algorithm is simple and repeated, you check all 8 positions around a spot every time with 8 if()
it is used throughout the whole code*/

void generate(int scr[100][100],int size,int mines);//generate random positions with mines and neutral spots
void hide_screen(char hide[100][100], int size); //hide screen behind '+' signs
void show_game(char hide[100][100], int size); //show the game screen so you can start playing
int check_flag(char hide[100][100],int x,int y,int size); //check if there is flag or not
void open(int scr[100][100],char hide[100][100],int a, int b,int size,clock_t begin);  //open a position
void reveal(int scr[100][100],char hide[100][100],int x,int y,int size);  //show current position
void revealall(int scr[100][100],char hide[100][100],int size);//reveal all screen
int check_dash(char hide[100][100], int size); //check if there is a mine or not around a spot

int main()
{
    srand(time(NULL));// optomize rand,by making use of the computer's internal clock to control the choice of the seed.
    game();
    return 0;
}

int game()
{
    char c,g,key;
    int scr[100][100]= {0}; //'1-8' is neutral place, '9' is a bomb,'91' is a flag, '10' is a dash where there is no mine around this position
    int mines,size;
    int i,j,p=0,f=0;//used as a flag or as a counter in other functions
    int a,b;// to let the user pick position to click on
    char hide[100][100];//where the '-', '+' or '*'  will be placed
    system("cls");
    do
    {
    printf("Enter # of Mines : ");
    scanf("%d",&mines);
    }while(mines<=0);
    do
    {
    printf("\nSize of Grid X*X : ");
    scanf("%d",&size);
    }while(size<=1);
    generate(scr,size,mines);
    hide_screen(hide, size);
    system("cls");
    show_game(hide,size);
    f=mines;
    while(1) //run as long as you don't exit
    {
        clock_t begin = clock();
        printf("\n\t1-click\n\t2-flag\n\t");
        scanf("%c%c",&g,&key);
        if(key=='1')
        {
            printf("\nx : ");
            scanf("%d",&a);
            a--;
            printf("\ny : ");
            scanf("%d",&b);
            b--;
            if(hide[a][b]!='F'&&hide[a][b]!='+')
            {
                int nf;
                nf=check_flag(hide,a,b,size);
                if(scr[a][b]>0&&scr[a][b]<9&&scr[a][b]<=nf)
                {
                    if(a+1 < size && b+1<size)
                        if(hide[a+1][b+1]!='F')
                        {
                            open(scr,hide,a+1,b+1,size,begin);
                            if(scr[a+1][b+1]==9||scr[a+1][b+1]==91)
                            {
                                break;
                            }
                        }
                    if(a+1 < size && b-1>=0)
                        if(hide[a+1][b-1]!='F')
                        {
                            open(scr,hide,a+1,b-1,size,begin);
                            if(scr[a+1][b-1]==9||scr[a+1][b-1]==91)
                            {
                                break;
                            }
                        }
                    if(a-1 >= 0 && b+1<size)
                        if(hide[a-1][b+1]!='F')
                        {
                            open(scr,hide,a-1,b+1,size,begin);
                            if(scr[a-1][b+1]==9||scr[a-1][b+1]==91)
                            {
                                break;
                            }
                        }
                    if(a-1 >=0 && b-1>=0)
                        if(hide[a-1][b-1]!='F')
                        {
                            open(scr,hide,a-1,b-1,size,begin);
                            if(scr[a-1][b-1]==9||scr[a-1][b-1]==91)
                            {
                                break;
                            }
                        }
                    if( b+1<size)
                        if(hide[a][b+1]!='F')
                        {
                            open(scr,hide,a,b+1,size,begin);
                            if(scr[a][b+1]==9||scr[a][b+1]==91)
                            {
                                break;
                            }
                        }
                    if(a+1 < size)
                        if(hide[a+1][b]!='F')
                        {
                            open(scr,hide,a+1,b,size,begin);
                            if(scr[a+1][b]==9||scr[a+1][b]==91)
                            {
                                break;
                            }
                        }
                    if(a-1 >= 0)
                        if(hide[a-1][b]!='F')
                        {
                            open(scr,hide,a-1,b,size,begin);
                            if(scr[a-1][b]==9||scr[a-1][b]==91)
                            {
                                break;
                            }
                        }
                    if( b-1 >= 0)
                        if(hide[a][b-1]!='F')
                        {
                            open(scr,hide,a,b-1,size,begin);
                            if(scr[a][b-1]==9||scr[a][b-1]==91)
                            {
                                break;
                            }
                        }

                }
            }
            else if(hide[a][b]=='+')
            {
                if(scr[a][b]==9||scr[a][b]==91)
                {
                    open(scr,hide,a,b,size,begin);
                    break;
                }
                else
                    open(scr,hide,a,b,size,begin);
            }
            system("cls");
            p = check_dash(hide,size);
            if(p==mines)
            {
                show_game(hide,size);
                printf("\nYou Win");
                clock_t end = clock();
                printf("\nelapsed time: %.2f seconds\n",(double)(end - begin)/CLOCKS_PER_SEC);
                break;
            }
            show_game(hide,size);
        }
        else if(key=='2')
        {
            printf("\nx : ");
            scanf("%d",&a);
            a--;
            printf("\ny : ");
            scanf("%d",&b);
            b--;
            system("cls");
            if(hide[a][b]!='F'&&hide[a][b]=='+')
            {
                hide[a][b]='F';
            }
            else if(hide[a][b]=='F')
            {
                hide[a][b]='+';
            }
            if(scr[a][b]==9&&hide[a][b]=='F')
            {
                f--;
                scr[a][b]=91;
            }
            if(f==0)
            {
                system("cls");
                revealall(scr,hide,size);
                show_game(hide,size);
                printf("\nYou Win");
                clock_t end = clock();
                printf("\nelapsed time: %.2f seconds\n",(double)(end - begin)/CLOCKS_PER_SEC);
                break;
            }
            else
                show_game(hide,size);
        }
    }
    do
    {
        printf("\n\t 'R'etry or 'E'xit ?  ");
        scanf("%c%c",&g,&c);
        if (c=='r'||c=='R') game();
        else if (c=='e'||c=='E') exit(0);
    }
    while(c!= 'E'||c!= 'e'||c!= 'R'||c!= 'r');
}

void hide_screen(char hide[100][100], int size)
{
    int i, j ;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
            hide[i][j]='+';
        printf("\n");
    }
}
void generate(int scr[100][100],int size,int mines)
{
    int i, j, x, y;
    for(i=0; i<mines; i++)
    {
        x = rand()%size;
        y=rand()%size;
        if(scr[x][y]!=9)
        {
            scr[x][y]=9;
            if(x+1 < size && y+1<size)
                if(scr[x+1][y+1]!=9)
                    scr[x+1][y+1]++;
            if(x+1 < size && y-1>=0)
                if(scr[x+1][y-1]!=9)
                    scr[x+1][y-1]++;
            if(x-1 >= 0 && y+1<size)
                if(scr[x-1][y+1]!=9)
                    scr[x-1][y+1]++;
            if(x-1 >=0 && y-1>=0)
                if(scr[x-1][y-1]!=9)
                    scr[x-1][y-1]++;
            if( y+1<size)
                if(scr[x][y+1]!=9)
                    scr[x][y+1]++;
            if(x+1 < size)
                if(scr[x+1][y]!=9)
                    scr[x+1][y]++;
            if(x-1 >= 0)
                if(scr[x-1][y]!=9)
                    scr[x-1][y]++;
            if( y-1 >= 0)
                if(scr[x][y-1]!=9)
                    scr[x][y-1]++;
        }
        else
            i--;
    }
}
void reveal(int scr[100][100],char hide[100][100],int x,int y,int size)
{
    if(hide[x][y]=='+')
    {
        if(scr[x][y]<=9 && scr[x][y]>0)
            hide[x][y]=scr[x][y]+'0';
        else
            hide[x][y]='-';
    }
    if (scr[x][y]==0)
    {
        scr[x][y]=10;
        hide[x][y]='-';
        if(x+1 < size && y+1<size)
            if(hide[x+1][y+1]=='+')
                reveal(scr,hide,x+1,y+1,size);
        if(x+1 < size && y-1>=0)
            if(hide[x+1][y-1]=='+')
                reveal(scr,hide,x+1,y-1,size);
        if(x-1 >= 0 && y+1<size)
            if(hide[x-1][y+1]=='+')
                reveal(scr,hide,x-1,y+1,size);
        if(x-1 >=0 && y-1>=0)
            if(hide[x-1][y-1]=='+')
                reveal(scr,hide,x-1,y-1,size);
        if( y+1<size)
            if(hide[x][y+1]=='+')
                reveal(scr,hide,x,y+1,size);
        if(x+1 < size)
            if(hide[x+1][y]=='+')
                reveal(scr,hide,x+1,y,size);
        if(x-1 >= 0)
            if(hide[x-1][y]=='+')
                reveal(scr,hide,x-1,y,size);
        if( y-1 >= 0)
            if(hide[x][y-1]=='+')
                reveal(scr,hide,x,y-1,size);
    }
}
void show_game(char hide[100][100], int size)
{
    int i, j, f ;
    printf(" y");
    for(i=1; i<size+1; i++)
        printf("   %d",i);
    printf("\n");
    for(i=1; i<size; i++)
    {
        if(i==1)
            printf("x   -");
        printf("-----",i);
    }
    printf("\n");
    f=1;
    for(i=0; i<size; i++)
    {
        printf("%d  | ",f);
        for(j=0; j<size; j++)
        {
            printf("%c   ",hide[i][j]);
        }
        printf("|");
        printf("\n");
        f++;
    }
    printf("\b");
    for(i=1; i<size; i++)
    {
        if(i==1)
            printf("    -");
        printf("-----",i);
    }
}

int check_dash(char hide[100][100], int size)
{
    int i, j, f ;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(hide[i][j]=='+'||hide[i][j]=='F')
            {
                f++;
            }
        }
    }
    return f;
}
void revealall(int scr[100][100],char hide[100][100],int size)
{
    int i, j;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if(scr[i][j]==9||scr[i][j]==91)
            {
                hide[i][j]='*';
            }
            else if(scr[i][j]==0||scr[i][j]==10)
            {
                hide[i][j]='-';
            }
            else
                hide[i][j]=scr[i][j]+'0';
        }
    }
}
void open(int scr[100][100],char hide[100][100],int a, int b,int size,clock_t begin)
{
    if(scr[a][b]==9||scr[a][b]==91||hide[a][b]=='*')
    {
        printf("\nloser");
        system("cls");
        revealall(scr,hide,size);
        show_game(hide,size);
        printf("\nloser");
        clock_t end = clock();
        printf("\nelapsed time: %.2f seconds\n",(double)(end - begin)/CLOCKS_PER_SEC);
    }
    else if(scr[a][b]!=0)
    {

        if(scr[a][b]==10)
            hide[a][b]='-';
        else
            hide[a][b]=scr[a][b]+'0';
    }
    else
    {
        reveal(scr,hide,a,b,size);
    }
}
int check_flag(char hide[100][100],int x,int y,int size)
{
    int f=0;
    if(x+1 < size && y+1<size)
        if(hide[x+1][y+1]=='F')
            f++;
    if(x+1 < size && y-1>=0)
        if(hide[x+1][y-1]=='F')
            f++;
    if(x-1 >= 0 && y+1<size)
        if(hide[x-1][y+1]=='F')
            f++;
    if(x-1 >=0 && y-1>=0)
        if(hide[x-1][y-1]=='F')
            f++;
    if( y+1<size)
        if(hide[x][y+1]=='F')
            f++;
    if(x+1 < size)
        if(hide[x+1][y]=='F')
            f++;
    if(x-1 >= 0)
        if(hide[x-1][y]=='F')
            f++;
    if( y-1 >= 0)
        if(hide[x][y-1]=='F')
            f++;
    return f;
}


