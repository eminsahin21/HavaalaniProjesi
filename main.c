#include <stdio.h>
#include <stdlib.h>

                                //190201088 Mehmet Emin Þahin
                                //190201010 Alperen Yurduseven
struct ucak
{
    int oncelik_id;
    int ucak_id;
    int talep_edilen_inis_saati;
};
struct ucak input;
int id_oncelik[40];
int id_ucak[40];
int talep_saati[40];
int ertelemeSayisi[40]= {0};
int silinen_eleman[40]={0};

int global_sayac1=0;
int global_sayac2=0;

int id_tut;
int sayi_tut;

void anamenu()
{
    int secim;
    system("cls");

    printf("\n\n\n\n\t\t______________ANAMENU_______________\n\n\n");
    printf("\t\t1)Dosyadan Veri Oku\n\n\n");
    printf("\t\t2)Cikis\n\n\n\n");

    printf("\t\t************************************\n\n\n");
    printf("\t\tYapmak istediginiz islemi seciniz(1-2)\n\t\t");
    scanf("%d",&secim);

    switch(secim)
    {
    case 1:
        veri_oku();
        break;
    case 2:
        exit(1);
        break;
    }
}

void veri_oku()
{
    FILE *fp;
    system("cls");

    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("\n\nDosya acilamadi\n\n!!");
        exit(1);
    }
    int satir_sayisi=0,i=0;

    while(!feof(fp))
    {
        fscanf(fp,"%d %d %d",&input.oncelik_id,&input.ucak_id,&input.talep_edilen_inis_saati);
        id_oncelik[i]=input.oncelik_id;
        id_ucak[i]=input.ucak_id;
        talep_saati[i]=input.talep_edilen_inis_saati;

        printf("\n\t\tOkunan Input: ");
        printf("\t%d\t%d\t%d\n\n",input.oncelik_id,input.ucak_id,input.talep_edilen_inis_saati);

        satir_sayisi++;
        normal_izin_durumu(satir_sayisi);

        if(silinen_eleman[i]!=1)
        {
            printf("\n\n\n\t\t\t%d id li ucak icin inis izni verildi\n\n",i+1);
        }
        if(silinen_eleman[i]==1)
        {
            if(id_tut!=sayi_tut)
            {
                printf("\n\n\t%d ID li ucak daha oncelikli oldugundan %d  ID li ucak olarak Sabiha Gokcen Havaalanina yonlendiriliyorsunuz..\n",sayi_tut,id_tut);
            }
            else
            {
                 printf("\n\n\t3'den fazla ertelemeden dolayi %d  ID li ucak olarak Sabiha Gokcen Havaalanina yonlendiriliyorsunuz..\n",id_tut);
            }
        }

        i++;
        getch();
    }

    fclose(fp);
    printf("\n\t\t\tAnamenuye donmek icin bir tusa basiniz\n\n\t\t");
    getch();
    anamenu();
}

void eleman_sil(int index,int eleman_sayisi)
{
    id_tut=id_ucak[index];
    silinen_eleman[index]=1;
    for(int i=index; i<eleman_sayisi; i++)
    {
        id_oncelik[i]=id_oncelik[i+1];
        id_ucak[i]=id_ucak[i+1];
        talep_saati[i]=talep_saati[i+1];
        ertelemeSayisi[i]=ertelemeSayisi[i+1];
    }
}

int main()
{
    system("color 0a");

    printf("\n\n\n\n\t\t\t------------------- HAVALIMANI UCUS TAKIP SISTEMI ----------------------\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|          <--Menuye gitmek icin herhangi bir tusa basiniz-->          |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t|                                                                      |\n");
    printf("\t\t\t************************************************************************\n\n\n\t\n\t\t\t\t\t\t\t");

    getch();
    anamenu();

    return 0;
}
void normal_izin_durumu(int eleman_sayisi)
{
    sayi_tut=eleman_sayisi;

    if(eleman_sayisi<=28)
    {

        for(int i=1; i<eleman_sayisi; i++)
        {

            for(int j=0; j<eleman_sayisi-1; j++)
            {

                if(talep_saati[eleman_sayisi-1]!=talep_saati[j])
                {
                    if(talep_saati[j]>talep_saati[j+1])
                    {

                        sirala(talep_saati,j);
                        sirala(id_oncelik,j);
                        sirala(id_ucak,j);
                        sirala(ertelemeSayisi,j);

                    }

                }

                if(talep_saati[eleman_sayisi-1]==talep_saati[j])
                {
                    if(ertelemeSayisi[eleman_sayisi-1]<=3 && ertelemeSayisi[j]<=3)
                    {

                        if(id_oncelik[eleman_sayisi-1]<id_oncelik[j])
                        {

                            int temp=id_oncelik[j];
                            id_oncelik[j]=id_oncelik[eleman_sayisi-1];
                            id_oncelik[eleman_sayisi-1]=temp;

                            int temp3=id_ucak[j];
                            id_ucak[j]=id_ucak[eleman_sayisi-1];
                            id_ucak[eleman_sayisi-1]=temp3;


                            int temp4=ertelemeSayisi[j];
                            ertelemeSayisi[j]=ertelemeSayisi[eleman_sayisi-1];
                            ertelemeSayisi[eleman_sayisi-1]=temp4;

                            talep_saati[eleman_sayisi-1]+=1;
                            ertelemeSayisi[eleman_sayisi-1]+=1;

                        }

                        else
                        {

                            talep_saati[eleman_sayisi-1]+=1;
                            ertelemeSayisi[eleman_sayisi-1]+=1;
                        }
                    }
                    if(ertelemeSayisi[eleman_sayisi-1]>3)
                    {
                        global_sayac1++;
                        global_sayac2++;
                        eleman_sil(eleman_sayisi-1,eleman_sayisi);

                    }
                    if(ertelemeSayisi[j]>3)
                    {
                        global_sayac1++;
                        global_sayac2++;
                        eleman_sil(j,eleman_sayisi);

                    }
                }
            }
        }
        yazdir(eleman_sayisi);
    }

}

void yazdir(int eleman_sayisi)
{
    FILE *fp;
    fp=fopen("output.txt","w");

    printf("\t\t\t");
    system("pause");
    system("cls");
    if(global_sayac1==0)
    {
        printf("\n\n\t\tKuyruk: ");
        for(int x=0; x<eleman_sayisi; x++)
        {
            if(id_ucak[x]>0)
            {

                printf("%d-",id_ucak[x]);

                if(ertelemeSayisi[x]>0)
                {
                    fprintf(fp,"%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",id_oncelik[x],id_ucak[x],talep_saati[x]-ertelemeSayisi[x],talep_saati[x],ertelemeSayisi[x],talep_saati[x]+1);
                }
                else
                {
                    if(talep_saati[x]>=24)
                        fprintf(fp,"%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",id_oncelik[x],id_ucak[x],talep_saati[x]-ertelemeSayisi[x],talep_saati[x]%24,ertelemeSayisi[x],(talep_saati[x]%24)+1);
                    else
                    {
                        fprintf(fp,"%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",id_oncelik[x],id_ucak[x],talep_saati[x]-ertelemeSayisi[x],talep_saati[x],ertelemeSayisi[x],talep_saati[x]+1);

                    }

                }
            }
        }
    }
    else
    {
        printf("\n\n\t\tKuyruk: ");
        for(int x=global_sayac2; x<eleman_sayisi; x++)
        {
            if(id_ucak[x]>0)
            {
                printf("%d-",id_ucak[x]);
                fprintf(fp,"%3d\t%3d\t%3d\t%3d\t%3d\t%3d\n",id_oncelik[x],id_ucak[x],talep_saati[x]-ertelemeSayisi[x],talep_saati[x],ertelemeSayisi[x],talep_saati[x]+1);
            }
        }
        global_sayac1=0;
    }
        fclose(fp);
}
void sirala(int dizi[],int index)
{
    int temp=dizi[index];
    dizi[index]=dizi[index+1];
    dizi[index+1]=temp;
}
