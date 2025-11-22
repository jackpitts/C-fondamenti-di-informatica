#define LEN_CHAR 50
#include <stdio.h>

int main()
{

    float v0_ms;
    float a_ms2;
    float s_m = 0.0;
    int s_tot_m;
    int T_STEP_S = 0;

    printf("Inserisci la velocità iniziale (m/s): ");
    scanf("%f", &v0_ms);
    printf("Inserisci l'accelerazione (m/s^2): ");
    scanf("%f", &a_ms2);
    printf("Inserisci la distanza totale (m): ");
    scanf("%d", &s_tot_m);

    printf("\n\nInizio simulazione: v0_ms = %.2f (m/s)\t a_ms2 = %.2f (m/s^2)\t s_tot_m = %d (m)\t step_s = 10 (s)\n\n", v0_ms, a_ms2, s_tot_m);

    do
    {
        printf("Tempo = %d\t", T_STEP_S);
        float v_ms = v0_ms + a_ms2 * T_STEP_S;
        printf("Velocità = %.2f m/s = %.2f km/h\t", v_ms, v_ms * 3.6);

        s_m = 1.0 / 2.0 * a_ms2 * (T_STEP_S * T_STEP_S) + v0_ms * T_STEP_S;
        printf("Distanza = %.2f m = %.3f km\n", s_m, s_m / 1000.0);

        int s_char = (int)(s_m * ((float)LEN_CHAR / s_tot_m));

        for (int i = 0; i < LEN_CHAR; i++)
        {
            if (i == 0)
            {
                if (s_char == 0)
                {
                    printf("0 X"); // oggetto all'inizio
                }
                else
                {
                    printf("0 ");
                }
            }
            else if (i == LEN_CHAR - 1)
            {
                printf(" %d", s_tot_m);
            }
            else if (i == s_char - 1 && s_char > 0)
            {
                printf("X");
            }
            else
            {
                printf("-");
            }
        }
        printf("\n\n");

        T_STEP_S += 10;
    } while (s_m <= s_tot_m);

    printf("Fine simulazione.\n\n");

    return 0;
}