#include <stdio.h>
#include <time.h>
#include <math.h>
int main(){
    double seata, val, u, m, x, Hy, Hx, tAir, t, Hg, r;
    double PI = 3.14159265;
    double g = 9.81;
    double HG = 2.44;
    val = PI / 180;
    char ch;

    printf("This is the program calculated the effects of shoot your Goal from the angle, force and distance.\n");

    do
    {
        printf("\n");
        printf("force (m/s) : ");
           while (scanf("%lf%c",&u,&ch)==0 || ch!='\n')
                {
                    rewind(stdin);
                    printf("Invalid input, please try again : ");
                }
        printf("angle (degree) : ");
            while (scanf("%lf%c",&seata,&ch)==0 || ch!='\n')
                {
                    rewind(stdin);
                    printf("Invalid input, please try again : ");
                }
        printf("distance from goal (m) : ");
         while (scanf("%lf%c",&x,&ch)==0 || ch!='\n')
                {
                    rewind(stdin);
                    printf("Invalid input, please try again : ");
                }

        r = seata*val;
        Hy = (pow(u*sin(r),2))/(2*g);
        Hx = (u*u*sin((2*r)))/g;
        tAir = (2*u*sin(r))/g;
        t = x/(u*cos(r));
        Hg = ((u*sin(r))*t)-(g*t*t)/2;

        printf("Maximum distance of the ball in vertical : %.2lf m.\n",Hy);
        printf("Maximum distance of the ball in horizon : %.2lf m.\n",Hx);
        printf("Ball float in the air long : %.2lf sec.\n",tAir);
        if(Hx<x)
        {
        printf("At the goal distance of the ball in vertical : %.2lf m.\n",x-Hx);
        printf("Use of time : %.2lf sec.\n",tAir);
        }
        else
        {
        printf("At the goal distance of the ball in vertical : %.2lf m.\n",Hg);
        printf("Use of time : %.2lf sec.\n",t);
        }

        if(Hx>x&&Hg<HG&&t<=0.5)
        {
            printf("\n");
            printf("       |||||||||||||||||||   |||||||||||||||||||             ||             ||                              \n");
            printf("       ||                    ||               ||            ||||            ||                              \n");
            printf("       ||                    ||               ||           ||  ||           ||                              \n");
            printf("       ||                    ||               ||          ||    ||          ||                              \n");
            printf("       ||                    ||               ||         ||      ||         ||                              \n");
            printf("       ||          |||||||   ||               ||        ||        ||        ||                              \n");
            printf("       ||               ||   ||               ||       ||||||||||||||       ||                              \n");
            printf("       ||               ||   ||               ||      ||            ||      ||                              \n");
            printf("       ||               ||   ||               ||     ||              ||     ||                              \n");
            printf("       |||||||||||||||||||   |||||||||||||||||||    ||                ||    ||||||||||||||                  \n");
            printf("\n");
            printf("Goal!!!!!!\n");
        }
        else
        {
            printf("YOU FAIL!!!\n");
            if(Hx<x)
            {
                printf("                                               _     ________           \n");
                printf("                                              / \\   |        \\        \n");
                printf("                                              \\_/   |         \\       \n");
                printf("                                              /|\\   |          \\      \n");
                printf("                                             / | \\  |           \\     \n");
                printf("                                _              /    |            \\     \n");
                printf("                               / \\            / \\   |             \\  \n");
                printf("                               \\_/           /   \\  |______________\\ \n");
                printf("\n");
                printf("The ball does not reach goal.\n");
            }
            else if(Hg>HG)
            {
                printf("                                                     _                  \n");
                printf("                                                    / \\                \n");
                printf("                                                    \\_/                \n");
                printf("                                               _     ________           \n");
                printf("                                              / \\   |        \\        \n");
                printf("                                              \\_/   |         \\       \n");
                printf("                                              /|\\   |          \\      \n");
                printf("                                             / | \\  |           \\     \n");
                printf("                                               /    |            \\     \n");
                printf("                                              / \\   |             \\   \n");
                printf("                                             /   \\  |______________\\  \n");
                printf("\n");
                printf("Ball over the goal.\n");
            }
            else if(t>0.5)
            {
                printf("                                               _     ________          \n");
                printf("                                              / \\   |        \\       \n");
                printf("                                             _\\_/   |         \\      \n");
                printf("                                            / \\|\\   |          \\    \n");
                printf("                                            \\_/|/   |           \\    \n");
                printf("                                               /    |            \\    \n");
                printf("                                              / \\   |             \\  \n");
                printf("                                             /   \\  |______________\\ \n");
                printf("\n");
               printf("The goalkeeper has time to pick up the ball.\n");
            }
        }

        do
        {
            printf("\n");
            printf("Enter y to calculate again or n to exit.");
            scanf(" %c",&ch);
        }
        while(ch!='y'&&ch!='n'&&ch!='Y'&&ch!='N');
        printf("##################################################################################################################\n");
    }
    while (ch == 'y'||ch == 'Y');
    printf("\nEnd Program\n");
    return 0;

}
