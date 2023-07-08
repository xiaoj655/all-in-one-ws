#include<bits/stdc++.h>

struct node {
  int data;
  node* next;
};

int main(){
  int m,n;scanf("%d %d",&m,&n);
  node *now,*p,*head,*prev;
  head = new node;
  prev = head;
  now = head;
  p = head;
  for(int i=1;i<m;i++){
    p->data = i;
    p->next = new node;
    p = p->next;
  }
  p->data = m;
  p->next = head;
  while((m--) > 1){
    for(int i=1;i<n;i++){
      prev = now;
      now = now->next;
    }
    prev->next = now->next;
    printf("%d ",now->data);
    delete now;
    now = prev->next;
  }
  printf("%d",now->data);
}
