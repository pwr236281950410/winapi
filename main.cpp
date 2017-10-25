#include <windows.h>
#include <assert.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>
#include <sstream>

#define PRZYCISK 501
#define PRZYCISK2 502
#define PRZYCISK3 503




using namespace std;


void pytania_i_odpowiedzi (void);
std::string pytania [ 3 ];
std::string odpowiedz1 [ 3 ];
std::string odpowiedz2 [ 3 ];
std::string odpowiedz3 [ 3 ];




template <class T>
string to_string(T obj)
{
    stringstream ss;
    ss << obj;
    return ss.str();
}

LPSTR NazwaKlasy = "Klasa Okienka";
MSG Komunikat;
HWND g_hPrzycisk;
HWND g_hPrzycisk2;
HWND g_hPrzycisk3;
HWND g_Koniec;
HINSTANCE hInstance;
HWND hText;
HWND aktualne_pytanie;
HWND punkty;
HWND na_piec;
HWND ilosc_punktow;



LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam );

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{

    // WYPE£NIANIE STRUKTURY **************************************************************************
    WNDCLASSEX wc;

    wc.cbSize = sizeof( WNDCLASSEX );
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground =( HBRUSH )( COLOR_WINDOW + 1  );
    wc.lpszMenuName = NULL;
    wc.lpszClassName = NazwaKlasy;
    wc.hIconSm = LoadIcon( NULL, IDI_APPLICATION );

    // REJESTROWANIE KLASY OKNA
    if( !RegisterClassEx( & wc ) )
    {
        MessageBox( NULL, "Wysoka Komisja odmawia rejestracji tego okna!", "Niestety...",
        MB_ICONEXCLAMATION | MB_OK );
        return 1;
    }





// TWORZENIE OKNA **********************************************************************************


    HWND hwnd;

    hwnd = CreateWindowEx( WS_EX_CLIENTEDGE, NazwaKlasy, "Oto okienko", WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, 700, 500, NULL, NULL, hInstance, NULL );



        if( hwnd == NULL )
        {
             MessageBox( NULL, "Okno odmówi³o przyjœcia na œwiat!", "Ale kicha...", MB_ICONEXCLAMATION );
            return 1;
        }

    ShowWindow( hwnd, nCmdShow ); // Poka¿ okienko...
    UpdateWindow( hwnd );





// Pêtla komunikatów *************************************************************************************
        while( GetMessage( & Komunikat, NULL, 0, 0 ) )
        {
            TranslateMessage( & Komunikat );
            DispatchMessage( & Komunikat );
        }
    return Komunikat.wParam;







}

// OBS£UGA ZDARZEÑ *******************************************************************************************
    LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
    {
    pytania_i_odpowiedzi();
    static int ii = 0;
    static int il= 0;
    static int ktore = 1;
    static int pom = 4;



        switch( msg )
        {


        case WM_CREATE:
        {
            //Pytania i odpowiedzi
                hText = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 50, 50, 270, 20,
                hwnd, NULL, hInstance, NULL );
                SetWindowText( hText,  pytania[ii].c_str());


                g_hPrzycisk = CreateWindowEx( 0, "BUTTON", odpowiedz1[ii].c_str(), WS_CHILD | WS_VISIBLE,
                100, 100, 150, 30, hwnd, (HMENU)PRZYCISK, hInstance, NULL );

                g_hPrzycisk2 = CreateWindowEx( 0, "BUTTON", odpowiedz2[ii].c_str(), WS_CHILD | WS_VISIBLE,
                100, 150, 150, 30, hwnd, (HMENU)PRZYCISK2, hInstance, NULL );

                g_hPrzycisk3 = CreateWindowEx( 0, "BUTTON", odpowiedz3[ii].c_str(), WS_CHILD | WS_VISIBLE,
                100, 200, 150, 30, hwnd, (HMENU)PRZYCISK3, hInstance, NULL );



            //Informowanie, ktore mamy aktualnie pytanie
                aktualne_pytanie = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 500, 300, 20, 20,
                hwnd, NULL, hInstance, NULL );
                SetWindowText( aktualne_pytanie, to_string(ktore).c_str());

                na_piec = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 508, 300, 20, 20,
                hwnd, NULL, hInstance, NULL );
                SetWindowText( na_piec, "/3");

            //Ilosc punktow

                ilosc_punktow = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 403, 200, 95, 20,
                hwnd, NULL, hInstance, NULL );
                SetWindowText( ilosc_punktow, "Ilosc punktow:");

                punkty = CreateWindowEx( 0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, 500, 200, 12, 20,
                hwnd, NULL, hInstance, NULL );
                SetWindowText( punkty, to_string(il).c_str());

            break;
        }

        case WM_COMMAND:

            {

                if (pom == 4)
                    {

                        pom++;
                            if ((HWND) lParam == g_hPrzycisk)
                                {
                                    ii++;
                                    ktore++;
                                    il--;
                                    SetWindowText( hText,  pytania[ii].c_str() );
                                    SetWindowText( g_hPrzycisk, odpowiedz1[ii].c_str()) ;
                                    SetWindowText( g_hPrzycisk2, odpowiedz2[ii].c_str()) ;
                                    SetWindowText( g_hPrzycisk3, odpowiedz3[ii].c_str()) ;
                                    SetWindowText( aktualne_pytanie,  to_string(ktore).c_str());

                                    SetWindowText( punkty, to_string(il).c_str());
                                    SetWindowText( na_piec, "/3");
                                    SetWindowText( ilosc_punktow, "Ilosc punktow:");
                                }
                            else if ((HWND) lParam == g_hPrzycisk2)
                                {

                                    ii++;
                                    ktore++;
                                    il++;
                                    SetWindowText( hText,  pytania[ii].c_str() );
                                    SetWindowText( g_hPrzycisk, odpowiedz1[ii].c_str()) ;
                                    SetWindowText( g_hPrzycisk2, odpowiedz2[ii].c_str()) ;
                                    SetWindowText( g_hPrzycisk3, odpowiedz3[ii].c_str()) ;
                                    SetWindowText( aktualne_pytanie,  to_string(ktore).c_str());

                                    SetWindowText( punkty, to_string(il).c_str());
                                    SetWindowText( na_piec, "/3");
                                    SetWindowText( ilosc_punktow, "Ilosc punktow:");

                                }

                            else if ((HWND) lParam == g_hPrzycisk3)
                                {

                                    ii++;
                                    ktore++;
                                    il--;
                                    SetWindowText( hText,  pytania[ii].c_str() );
                                    SetWindowText( g_hPrzycisk, odpowiedz1[ii].c_str()) ;
                                    SetWindowText( g_hPrzycisk2, odpowiedz2[ii].c_str()) ;
                                    SetWindowText( g_hPrzycisk3, odpowiedz3[ii].c_str()) ;
                                    SetWindowText( aktualne_pytanie,  to_string(ktore).c_str());

                                    SetWindowText( punkty, to_string(il).c_str());
                                    SetWindowText( na_piec, "/3");
                                    SetWindowText( ilosc_punktow, "Ilosc punktow:");
                                }

                        break;

                    }




                     if (pom == 5)
                        {

                            pom++;
                                if ((HWND) lParam == g_hPrzycisk)
                                    {
                                        ii++;
                                        ktore++;
                                        il--;
                                        SetWindowText( hText,  pytania[ii].c_str() );
                                        SetWindowText( g_hPrzycisk, odpowiedz1[ii].c_str()) ;
                                        SetWindowText( g_hPrzycisk2, odpowiedz2[ii].c_str()) ;
                                        SetWindowText( g_hPrzycisk3, odpowiedz3[ii].c_str()) ;
                                        SetWindowText( aktualne_pytanie,  to_string(ktore).c_str());

                                        SetWindowText( punkty, to_string(il).c_str());
                                        SetWindowText( na_piec, "/3");
                                        SetWindowText( ilosc_punktow, "Ilosc punktow:");
                                    }
                                else if ((HWND) lParam == g_hPrzycisk2)
                                    {

                                        ii++;
                                        ktore++;
                                        il--;
                                        SetWindowText( hText,  pytania[ii].c_str() );
                                        SetWindowText( g_hPrzycisk, odpowiedz1[ii].c_str()) ;
                                        SetWindowText( g_hPrzycisk2, odpowiedz2[ii].c_str()) ;
                                        SetWindowText( g_hPrzycisk3, odpowiedz3[ii].c_str()) ;
                                        SetWindowText( aktualne_pytanie,  to_string(ktore).c_str());

                                        SetWindowText( punkty, to_string(il).c_str());
                                        SetWindowText( na_piec, "/3");
                                        SetWindowText( ilosc_punktow, "Ilosc punktow:");

                                    }

                                else if ((HWND) lParam == g_hPrzycisk3)
                                    {

                                        ii++;
                                        ktore++;
                                        il++;
                                        SetWindowText( hText,  pytania[ii].c_str() );
                                        SetWindowText( g_hPrzycisk, odpowiedz1[ii].c_str()) ;
                                        SetWindowText( g_hPrzycisk2, odpowiedz2[ii].c_str()) ;
                                        SetWindowText( g_hPrzycisk3, odpowiedz3[ii].c_str()) ;
                                        SetWindowText( aktualne_pytanie,  to_string(ktore).c_str());

                                        SetWindowText( punkty, to_string(il).c_str());
                                        SetWindowText( na_piec, "/3");
                                        SetWindowText( ilosc_punktow, "Ilosc punktow:");
                                    }

                            break;

                        }




                    if (pom == 6)
                        {

                            if ((HWND) lParam == g_hPrzycisk)
                            {
                                il++;
                            }


                            else if ((HWND) lParam == g_hPrzycisk2)
                            {
                                il--;
                            }

                            else if ((HWND) lParam == g_hPrzycisk3)
                            {
                                il--;
                            }

                            pom++;

                            DestroyWindow(g_hPrzycisk);
                            DestroyWindow(g_hPrzycisk2);
                            DestroyWindow(g_hPrzycisk3);
                            DestroyWindow(hText);

                            SetWindowText( aktualne_pytanie,  to_string(ktore).c_str());
                            SetWindowText( punkty, to_string(il).c_str());
                            SetWindowText( na_piec, "/3");
                            SetWindowText( ilosc_punktow, "Ilosc punktow:");

                g_Koniec = CreateWindowEx( 0, "BUTTON", "Koniec quizu", WS_CHILD | WS_VISIBLE,
                100, 200, 150, 60, hwnd, NULL, hInstance, NULL );


                            }
            if ((HWND) lParam == g_Koniec)
                        {
                            DestroyWindow( hwnd );
                            PostQuitMessage( 0 );
                            break;
                        }

            }
            break;
        case WM_CLOSE:
        DestroyWindow( hwnd );
            break;

        case WM_DESTROY:

        PostQuitMessage( 0 );

            break;

            default:
            return DefWindowProc( hwnd, msg, wParam, lParam );
        }

        return 0;
    }



void pytania_i_odpowiedzi (void)
{

pytania [0] = "Jak zdefiniowac zmienna inteeger w C?";
pytania [1] = "Ile razy wykona sie petla while(1)?";
pytania [2] = "Za pomoca [] tworzy sie:";


odpowiedz1 [0] = "inteeger zmienna";
odpowiedz1 [1] = "0";
odpowiedz1 [2] = "Tablice";


odpowiedz2 [0] = "int zmienna";
odpowiedz2 [1] = "1";
odpowiedz2 [2] = "Liczby";

odpowiedz3 [0] = "i zmienna";
odpowiedz3[1] = "Nieskonczona ilosc razy";
odpowiedz3 [2] = "Funkcje";



}



