#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

node* head = NULL;

void basaEkle(struct node* head_ref, int veri)
{
    struct node* yeniNode;          // Eklenecek node için alan
    yeniNode = malloc(sizeof(node));

    yeniNode->data = veri;           // basa ekleme algoritmasi
    yeniNode->next = head_ref->next;

    head_ref->next = yeniNode;      // ekleme islemi

    printf("basa eklendi \n");

}

void sonaEkle(struct node* head_ref, int veri)
{
    struct node* yeniNode;              // Eklenecek node icin alan
    yeniNode = malloc(sizeof(node));

    yeniNode->data = veri;
    yeniNode->next = NULL;

    struct node* trav = head_ref;        // traverse pointer
      while(trav->next != NULL)
        {
            trav = trav->next;
        }

    trav->next = yeniNode;              // ekleme islemi
    printf("sona eklendi \n");
}

void arayaEkle(int veri_ref, int veri)
{
    struct node* yeniNode;              // Eklenecek node icin alan
    yeniNode = malloc(sizeof(node));

    yeniNode->data = veri;
    yeniNode->next = NULL;

    struct node* trav = head;           // traverse node pointer

    while(trav->next->data != veri_ref)
    {
        trav = trav->next;
    }

    yeniNode->next = trav->next;   // ekleme islemi
    trav->next = yeniNode;
}

void Ekle(struct node* head_ref, int veri)
{
    if(head_ref->next != NULL)      // liste bos ise basa ekle
    {
        sonaEkle(head_ref,veri);
    }else
    {
       basaEkle(head_ref, veri); // bos degil ise sona ekle
    }
}

void Sil(struct node* veri_ref)
{
    node *tmpNode;

    node *trav = head;
    while(trav->next->data != veri_ref)
    {
        trav = trav->next;
    }

    tmpNode = trav->next;
    trav->next = tmpNode->next;
    free(tmpNode);
}

void sondanSil(struct node* head_ref)
{
    node *trav =head;
    while(trav->next->next != NULL)
    {
        trav = trav->next;
    }
    free(trav->next->next);
    trav->next = NULL;

}

void bastanSil(struct node* head_ref)
{
    if(head->next == NULL)
    {
        printf("Listede silinecek bir sey yok");
        return -1;
    }

    node *trav = head;
    node *tmpNode;

    tmpNode = trav->next;
    trav->next = tmpNode->next;
    free(tmpNode);
}

void yazdir(struct node* head_ref)
{
    while(head_ref->next!=NULL)
    {
        printf("%d---->", head_ref->next->data);
        head_ref = head_ref->next;
    }
    printf("\n");
}


int main()
{
    head = malloc(sizeof(node));
    head->data = NULL;
    head->next = NULL;

    Ekle(head,4);
    Ekle(head,3);
    Ekle(head,1);
    Ekle(head,7);
    Ekle(head,8);
    yazdir(head);

    arayaEkle(3,24);
    yazdir(head);

    Sil(8);
    yazdir(head);

    Sil(4);
    yazdir(head);

    sondanSil(head);
    yazdir(head);

    bastanSil(head);
    yazdir(head);
}
