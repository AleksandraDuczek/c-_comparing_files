#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream file1, file2;
    file1.open("plik.dat", ios::in | ios::binary);
    file2.open("plik_porownanie.dat", ios::in | ios::binary);

    int fileSize1, fileSize2;
    unsigned char buf1,buf2;
    char DataFile1[50];
    char DataFile2[50];
    int k=0;//miejsce w pliku 2 gdzie bajty sie zgadzaly//
    int dodane=0;
    int usuniete=0;
    int zmienione=0;
    int znalazl=0;//ile prawidlowych bajtow//

    file1.seekg(0, std::ios::end);
    fileSize1=file1.tellg();
    file1.seekg(0, std::ios::beg);


    file2.seekg(0, std::ios::end);
    fileSize2=file2.tellg();
    file2.seekg(0, std::ios::beg);



    for (int a=0; a<fileSize1; a++)//petla przechodzaca przez plik pierwszy//
    {
        file1.read((char*) &buf1, 1);//wczytanie bajt po bajcie z pliku 1//

        for (int b=k; b<fileSize2; b++)//petla przechodzaca przez drugi//
        {
            file2.read((char*) &buf2, 1);//wczytanie bajt po bajcie z 2//

            if(fileSize1<fileSize2)
            {

                    for (int i = a; i < fileSize1; i++)
                    {
                        file1.read((char*) &DataFile1[i], 1);//wczytujemy do tablicy charow//

                        for (int j = b; j < fileSize1; j++)
                        {
                            file2.read((char*) &DataFile2[j], 1);

                                        if (DataFile1[i]==DataFile2[j])
                               {
                                    znalazl++;//inkrementujemy gdy bajty sie zgadzaja//
                                    k++;//miejsce w pliku 2 gdzie bajty sie zgadzaja inkrementujemy//


                               }

                                    else //DataFile1[i]!=DataFile2[j]{


                                   {


                                    if (DataFile1[i+1] == DataFile2[j+1])//porownujemy bajty nastepne, bo niezgadzajacym sie, jesli nastepne sie zgadzaja, bo bajt rozniacy sie jest zmieniony//
                            {
                                zmienione++;


                            }
                            else if (DataFile1[i] == DataFile2[j+1])//porownujemy bajt ró?ni1cy sie z bajtem nastepnym, jeoli s1 równe, to zostalo cos pomiedzy nich dodane//
                            {
                                dodane++;
                                j=j+1;



                            }
                            else if (DataFile1[i+1] == DataFile2[j])//porownujemy bajt ró?ni1cy sie z bajtem poprzednim, jeoli s1 równe, to bajt ró?ni1cy sie zostal usuniety//
                            {

                                usuniete++;
                                i=i+1;



                            }


                            else //poszukujemy czy bajt rozniacy sie jest gdzies w dalszej czesci kodu//
                            {
                                for (int h=j; h<j+50; h++)
                                {

                                    if(DataFile1[i]==DataFile2[h])
                                    {
                                        j=h;
                                        int x=h-j;//od miejsca znalezienia bajtu do poprawnych bajtow//
                                        dodane=dodane+x;

				//jesli znajdziemy ten bajt to bajty miedzy nim a poprawnym zostaly dodane//
                                    }

                                    else //jesli nie znajdziemy tego bajtu to zostal on usuniety//
                                    {
                                        usuniete++;
                                        j=j-1;


                                    }
                                break;
                                    }

                        }


                    }
                    break;
                }
            }
            break;
      }


                else if (fileSize1>fileSize2)
                {

                    for (int i = a; i< fileSize2; i++)
                    {
                        file1.read((char*) &DataFile1[i], 1);//wczytujemy do tablicy charow//

                        for (int j = b; j < fileSize2; j++)
                        {
                            file2.read((char*) &DataFile2[j], 1);
                               if (DataFile1[i]==DataFile2[j])
                               {
                                    znalazl++;//inkrementujemy gdy bajty sie zgadzaja//
                                    k++;//miejsce w pliku 2 gdzie bajty sie zgadzaja inkrementujemy//


                               }

                                   else //DataFile1[i]!=DataFile2[j]{


                                   {
                                        if (DataFile1[i+1] == DataFile2[j+1])//porownujemy bajty nastepne, bo niezgadzajacym sie, jesli nastepne sie zgadzaja, bo bajt rozniacy sie jest zmieniony//
                            {
                                zmienione++;


                            }
                            else if (DataFile1[i] == DataFile2[j+1])//porownujemy bajt ró?ni1cy sie z bajtem nastepnym, jeoli s1 równe, to zostalo cos pomiedzy nich dodane//
                            {
                                dodane++;
                                i=i-1;



                            }
                            else if (DataFile1[j+1]=='\0')//jesli nastepny bajt po rozniacym sie jest pusty(koniec pliku) to bajty zostaly usuniete//
                            {
                                zmienione++;
                                usuniete+=(fileSize1-fileSize2);
                                   cout<<"Dodano : " <<dodane<< " bajtow "<<endl;
                                cout<<"Usunieto : " <<usuniete<< " bajtow "<<endl;
                                cout<<"Zmieniono : " <<zmienione<< " bajtow "<<endl;
                                system("PAUSE");

                            }
                            else if (DataFile1[i+1] == DataFile2[j])//porownujemy bajt ró?ni1cy sie z bajtem poprzednim, jeoli s1 równe, to bajt ró?ni1cy sie zostal usuniety//
                            {

                                usuniete++;
                                j=j-1;



                            }


                            else //poszukujemy czy bajt rozniacy sie jest gdzies w dalszej czesci kodu//
                            {
                                for (int h=j; h<j+50; h++)
                                {

                                    if(DataFile1[i]==DataFile2[h])
                                    {
                                        j=h;
                                        int x=h-j;
                                        dodane=dodane+x;

				//jesli znajdziemy ten bajt to bajty miedzy nim a poprawnym zostaly dodane//
                                    }

                                    else //jesli nie znajdziemy tego bajtu to zostal on usuniety//
                                    {
                                        usuniete++;
                                        j=j-1;


                                    }
                                    break;
                                    }




                        }
                                        break;


                    }

                            break;
                            }
                        }
                        break;
                    }

                    else if(fileSize1==fileSize2)
                    {

                        for (int i = a; i< fileSize1; i++)
                    {
                        file1.read((char*) &DataFile1[i], 1);//wczytujemy do tablicy charow//

                        for (int j = b; j < fileSize2; j++)
                        {
                            file2.read((char*) &DataFile2[j], 1);
                               if (DataFile1[i]==DataFile2[j])
                               {
                                    znalazl++;//inkrementujemy gdy bajty sie zgadzaja//
                                    k++;//miejsce w pliku 2 gdzie bajty sie zgadzaja inkrementujemy//


                               }

                                   else //DataFile1[i]!=DataFile2[j]{


                                   {
                                        if (DataFile1[i+1] == DataFile2[j+1])//porownujemy bajty nastepne, bo niezgadzajacym sie, jesli nastepne sie zgadzaja, bo bajt rozniacy sie jest zmieniony//
                            {
                                zmienione++;


                            }
                            else if (DataFile1[i] == DataFile2[j+1])//porownujemy bajt ró?ni1cy sie z bajtem nastepnym, jeoli s1 równe, to zostalo cos pomiedzy nich dodane//
                            {
                                dodane++;
                                i=i-1;



                            }

                            else if (DataFile1[i+1] == DataFile2[j])//porownujemy bajt ró?ni1cy sie z bajtem poprzednim, jeoli s1 równe, to bajt ró?ni1cy sie zostal usuniety//
                            {

                                usuniete++;
                                j=j-1;



                            }


                            else //poszukujemy czy bajt rozniacy sie jest gdzies w dalszej czesci kodu//
                            {
                                for (int h=j; h<j+50; h++)
                                {

                                    if(DataFile1[i]==DataFile2[h])
                                    {
                                        j=h;
                                        int x=h-j;
                                        dodane=dodane+x;

				//jesli znajdziemy ten bajt to bajty miedzy nim a poprawnym zostaly dodane//
                                    }

                                    else //jesli nie znajdziemy tego bajtu to zostal on usuniety//
                                    {
                                        usuniete++;
                                        j=j-1;


                                    }
                                    break;
                                    }




                        }
                                        break;


                    }

                            break;
                            }
                        }
                        break;
                    }

                break;
                    }
            break;
            }


              if(fileSize1==fileSize2)
            {

            cout<<"Dodano : " <<dodane<< " bajtow "<<endl;
            cout<<"Usunieto : " <<usuniete<< " bajtow "<<endl;
            cout<<"Zmieniono : " <<zmienione<< " bajtow "<<endl;
            system("PAUSE");


          }

          else if(fileSize2>(dodane+zmienione+znalazl-usuniete))
          {
              dodane=dodane+(fileSize2-(dodane+zmienione+znalazl-usuniete));
                cout<<"Dodano : " <<dodane<< " bajtow "<<endl;
            cout<<"Usunieto : " <<usuniete<< " bajtow "<<endl;
            cout<<"Zmieniono : " <<zmienione<< " bajtow "<<endl;
            system("PAUSE");


          }



          else if(fileSize2>fileSize1)
          {

              usuniete=(fileSize2-znalazl);
               cout<<"Dodano : " <<dodane<< " bajtow "<<endl;
            cout<<"Usunieto : " <<usuniete<< " bajtow "<<endl;
            cout<<"Zmieniono : " <<zmienione<< " bajtow "<<endl;
            system("PAUSE");

          }
           else if(fileSize1>fileSize2)
          {

              dodane=(fileSize1-znalazl);
               cout<<"Dodano : " <<dodane<< " bajtow "<<endl;
            cout<<"Usunieto : " <<usuniete<< " bajtow "<<endl;
            cout<<"Zmieniono : " <<zmienione<< " bajtow "<<endl;
            system("PAUSE");

          }
            else
            {


            cout<<"Dodano : " <<dodane<< " bajtow "<<endl;
            cout<<"Usunieto : " <<usuniete<< " bajtow "<<endl;
            cout<<"Zmieniono : " <<zmienione<< " bajtow "<<endl;
            system("PAUSE"); }


        return 0;
    }
