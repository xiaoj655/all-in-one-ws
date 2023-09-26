#include <iostream>
using namespace std;
#define ok 0
#define error -1

// 链表结点定义
class ListNode
{
public:
  int data;
  ListNode *next;
  ListNode() { next = NULL; }
};
// 带头结点的单链表类定义
class LinkList
{
public:
  ListNode *head;
  int len;
  // 操作定义
  LinkList();
  ~LinkList();
  ListNode *LL_index(int i);      // 返回第i个结点的指针，如果不存在返回NULL
  int LL_get(int i);              // 获取第i个元素的数据
  int LL_insert(int i, int item); // 把数值item插入第i个位置
  int LL_del(int i);              // 删除第i个结点
  void LL_display();              // 输出单链表的内容
};
LinkList::LinkList()
{
  head = new ListNode();
  len = 0;
}
LinkList::~LinkList()
{
  ListNode *p, *q;
  p = head;
  while (p != NULL)
  {
    q = p;
    p = p->next;
    delete q;
  }
  len = 0;
  head = NULL;
}
void LinkList::LL_display()
{
  ListNode *p;
  p = head;
  while (p)
  {
    cout << p->data << ' ';
    p = p->next;
  }
  cout << endl;
}

int LinkList::LL_get(int x)
{
  if(x>len || x <=0) return -1;
  ListNode *funny = head;
  for (int i = 0; i < x - 1; i++)
  {
    funny = funny->next;
  }
  return funny->data;
}

int LinkList::LL_insert(int i, int item)
{
  ListNode *funny = head;
  ListNode *funny2 = head;
  if(i == len+1){
    for(int i=0;i<len-1;i++){
      funny = funny->next;
    }
    ListNode* tem = new ListNode();
    tem->data = item;
    funny->next = tem;
    ++len;
    return 1;
  }
  if (i > len || i <= 0)
    return -1;

  for (int k = 0; k < i - 1; k++)
  {
    funny2 = funny;
    funny = funny->next;
  }

  ListNode *x = new ListNode();
  x->data = item;
  if (i != 1)
  {
    funny2->next = x;
    x->next = funny;
  }
  else
  {
    head = x;
    x->next = funny;
  }
  ++len;
  return 1;
}
ListNode *LinkList::LL_index(int i)
{
  ListNode *funny = head;
  for (int k = 0; k < i - 1; k++)
  {
    funny = funny->next;
  }
  return funny;
}

int LinkList::LL_del(int i)
{
  ListNode *funny = head;
  ListNode *funny2;
  if (i > len || i <= 0)
    return -1;
  for (int k = 0; k < i - 1; k++)
  {
    funny2 = funny;
    funny = funny->next;
  }
  if (i != 1)
  {
    funny2->next = funny->next;
  }
  else
  {
    head = head->next;
  }
  --len;
  return 1;
}

int main()
{
  int x;
  cin >> x;
  LinkList LL = LinkList();
  LL.len = x;
  int val;
  cin >> val;
  LL.head->data = val;
  ListNode *cur;
  cur = LL.head;
  for (int i = 1; i < x; i++)
  {
    cin >> val;
    ListNode *tem = new ListNode();
    tem->data = val;
    cur->next = tem;
    cur = cur->next;
  }
  LL.LL_display();

  int index;
  cin >> index;
  cin >> val;
  if (LL.LL_insert(index, val) != -1)
  {
    LL.LL_display();
  }
  else
  {
    cout << "error\n";
  }

  cin >> index;
  cin >> val;
  if (LL.LL_insert(index, val) != -1)
  {
    LL.LL_display();
  }
  else
  {
    cout << "error\n";
  }

  cin >> index;
  if (LL.LL_del(index) != -1)
  {
    LL.LL_display();
  }
  else
  {
    cout << "error\n";
  }
  cin >> index;
  if (LL.LL_del(index) != -1)
  {
    LL.LL_display();
  }
  else
  {
    cout << "error\n";
  }

  cin >> index;
  if (LL.LL_get(index) != -1)
  {
    cout << LL.LL_get(index);
  }
  else
  {
    cout << "error\n";
  }

  cin >> index;
  if (LL.LL_get(index) != -1)
  {
    cout << LL.LL_get(index);
  }
  else
  {
    cout << "error\n";
  }
}