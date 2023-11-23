#include<iostream>
using namespace std;
int const Max = 50;
struct queue {
	int front, rear;
	int list[Max];
};
void khoitao(queue& q) {
	q.front = -1;
	q.rear = -1;
}
int isEmpty(queue q) {
	return q.front == -1 ? 1 : 0;
}
int isFull(queue q) {
	return q.rear == Max - 1;
}
void creatQueue(queue& q, int n) {
	// n là số lượng phần tử trong list
	if (n > Max) {
		n = Max;
	}
	for (int i = 0; i < n; i++) {
		cin >> q.list[i];
		q.rear++;
	 }
	  if (isEmpty(q)) {
		q.front = 0;
	 }
}
void prinfQueue(queue q) {
	for (int i = q.front; i <= q.rear; i++) {
		cout << q.list[i] << " ";
	}
	if (isEmpty(q)) {
		cout << "\n danh sach rong!";
	}
}
// enQueue thêm phần tử vào trong hàng đợi
void enQueue(queue& q, int x) {
	if (isFull(q)) {
		cout << "\n hang doi day";
	}
	else {
		q.rear++;
		q.list[q.rear] = x;
		if (isEmpty(q)) {
			q.front = 0;
		}
	}
}
int deQueue(queue& q) {
	int gt;
	if (isFull(q)) {
		return -99;
	}
	else {
		gt = q.list[q.front];
		q.front++;
		if (q.front > q.rear) {
			khoitao(q);
		}
	}
	return gt;
}
void refeshQueue(queue& q) {
	int j = 0;
	for (int i = q.front; i <= q.rear; i++) {
		q.list[j] = q.list[i];
	}
	q.rear = q.rear - q.front;
	q.front = 0;
}
void chenX(queue& q, int x) {
	queue Qt;
	khoitao(Qt);
	while (!isEmpty(q)) {
		int pt = deQueue(q);
		if (pt <= x) {
			enQueue(Qt, pt);
		}
		else {
			enQueue(Qt, x);
			enQueue(Qt, pt);
			break;
		}
	}
	while (!isEmpty(q)) {
		int pt = deQueue(q);
		enQueue(Qt, pt);
	}
	while (!isEmpty(Qt)) {
		int pt = deQueue(Qt);
		enQueue(q, pt);
	}
}
void xoaX(queue& q, int x) {
	queue Qt;
	khoitao(Qt);
	while (!isEmpty(q)) {
		int pt = deQueue(q);
		if (pt != x) {
			enQueue(Qt, pt);
		}
	}
	while (!isEmpty(Qt)) {
		int pt = deQueue(Qt);
		enQueue(q, pt);
	}
}
void xuatAllx(queue q, int x) {
	for (int i = q.front; i <= q.rear; i++) {
		if (q.list[i] == x) {
			cout << i << " ";
		}
	}
}
int demX(queue q, int x) {
	int dem = 0;
	for (int i = q.front; i <= q.rear; i++) {
		if (q.list[i] == x) {
			dem++;
		}
	}
	return dem;
}
void Pop(queue& q, int x) {
	if (isFull(q)) {
		cout << "\n danh sach day";
	}
	else {
		q.rear++;
		q.list[q.rear] = x;
		if (isEmpty(q)) {
			q.front = 0;
		}
	}
}
int Push(queue& q) {
	int pt;
	if (isFull(q)) {
		return -99;
	}
	else {
		 pt = q.list[q.front];
		q.front++;
		if (q.front > q.rear) {
			khoitao(q);
		}
	}
	return pt;
}
void xoaXdau(queue& q, int x) {
	queue Qt,xoa;
	khoitao(xoa);
	int flag = 0;
	khoitao(Qt);
	while (!isEmpty(q)) {
		int pt = Push(q);
		if (pt == x && flag == 0) {
			Pop(xoa, pt);
			flag++;
		}
		else {
			Pop(Qt, pt);
		}
	}
	while (!isEmpty(Qt)) {
		int pt = Push(Qt);
		Pop(q, pt);
	}
}
void xoaXcuoi(queue& q, int x) {
	queue Qt, xoa;
	int flag = 0;
	int dem = 0;
	khoitao(Qt); khoitao(xoa);
	for (int i = q.front; i <= q.rear; i++) {
		if (q.list[i] == x) {
			dem++;
		}
	}
	while (!isEmpty(q)) {
		int pt = Push(q);
		if (pt == x) {
			flag++;
			if (flag == dem) {
				Pop(xoa, pt);
			}
			else {
				Pop(Qt, pt);
			}
		}
		else {
			Pop(Qt, pt);
		}
	}
	while (!isEmpty(Qt)) {
		int pt = Push(Qt);
		Pop(q, pt);
	}
}
void xoaXthu2(queue& q, int x) {
	queue Qt, xoa;
	khoitao(xoa);
	int flag = 0;
	khoitao(Qt);
	while (!isEmpty(q)) {
		int pt = Push(q);
		if (pt == x ) {
			flag++;
			if (flag == 2) {
				Pop(xoa, pt);
			}
			else {
				Pop(Qt, pt);
			}
		}
		else {
			Pop(Qt, pt);
		}
	}
	while (!isEmpty(Qt)) {
		int pt = Push(Qt);
		Pop(q, pt);
	}
}
void chenYsauX(queue& q, int x,int y) {
	queue Qt;
	khoitao(Qt);
	while (!isEmpty(q)) {
		int pt = Push(q);
		if (pt != x) {
			Pop(Qt, pt);
		}
		else {
			Pop(Qt, pt);
			Pop(Qt, y);
		}
	}
	while (!isEmpty(Qt)) {
		int pt = Push(Qt);
		Pop(q, pt);
	}
}
void chenXTang(queue& q, int x) {
	queue Qt;
	khoitao(Qt);
	while (!isEmpty(q)) {
		int pt = Push(q);
		if (pt <= x) {
			Pop(Qt, pt);
		}
		else {
			Pop(Qt, x);
			Pop(Qt, pt);
			break;
		}
	}
	while (!isEmpty(q)) {
		int pt = Push(q);
		Pop(Qt, pt);
	}
	while (!isEmpty(Qt)) {
		int pt = Push(Qt);
		Pop(q, pt);
	}
}
void tronQ1Q2Tang(queue& q1, queue& q2) {
	queue q;
	khoitao(q);
	while (!isEmpty(q1) && !isEmpty(q2)) {
		int s1 = Push(q1);
		int s2 = Push(q2);
		if (s1 > s2) {
			Pop(q, s2);
			Pop(q, s1);
		}
		else {
			Pop(q, s1);
			Pop(q, s2);
		}
	}
	while (!isEmpty(q1)) {
		int pt = Push(q1);
		Pop(q, pt);
	}
	while (!isEmpty(q2)) {
		int pt = Push(q2);
		Pop(q, pt);
	}
	prinfQueue(q);
}
void tachChanLe(queue& q) {
	queue q1, q2;
	khoitao(q1); khoitao(q2);
	while (!isEmpty(q)) {
		int pt = Push(q);
		if (pt % 2 == 0) {
			Pop(q1, pt);
		}
		else {
			Pop(q2, pt);
		}
	}
	cout << "\n danh sach Q1: "<<endl;
	prinfQueue(q1);
	cout << "\n danh sach Q2: " << endl;
	prinfQueue(q2);
}
void noiQ1voaQ2(queue& q1, queue& q2) {
	while (!isEmpty(q1)) {
		int pt = Push(q1);
		Pop(q2, pt);
	}
	cout << "\n danh sach sau khi noi: ";
	prinfQueue(q2);
}
int main() {
	/*queue a;
	khoitao(a);
	creatQueue(a, 7);*/
	//prinfQueue(a);
	///*int x;
	//cout << "\n nhap phan tu can them: ";
	//cin >> x;
	//enQueue(a, x);
	//prinfQueue(a);*/
	//chenYsauX(a, 2,22);
	//cout << "\n================="<<endl;
	//prinfQueue(a);
	queue q1, q2,q;
	khoitao(q1); khoitao(q2);
	creatQueue(q1, 3);
	cout << "\n nhap danh sach 2: " << endl;
	creatQueue(q2, 4);
	noiQ1voaQ2(q1, q2);
	return 0;
}


============================================
     CAU TRUC QUEUE DSLK-DON
===========================================

#include<iostream>
using namespace std;
int const Max = 50;
struct node {
	int data;
	node* link;
};
typedef struct node* nodeptr;
struct queue {
	nodeptr front;
	nodeptr rear;
};
void khoitao(queue& q) {
	q.front = NULL;
	q.rear = NULL;
}
int isEmpty(queue q) {
	return (q.front == NULL && q.rear == NULL) ? 1 : 0;
}
nodeptr creatnode(int x) {
	nodeptr p = new node;
	if (p == NULL) {
		cout << "\n khong du bo nho!";
		return NULL;
	}
	p->data = x;
	p->link = NULL;
	return p;
}
void Push(queue& q, nodeptr p) {
	if (q.front == NULL) {
		q.front = p;
		q.rear = p;
	}
	else {
		q.rear->link = p;
		q.rear = p;

	}
}
nodeptr Pop(queue& q) {
	nodeptr p = new node;
	if (isEmpty(q)) {
		cout << "\n danh sach rong";
		return NULL;
	}
	p = q.front;
	q.front = q.front->link;
	if (q.front == NULL) {
		q.rear = NULL;
	}
	return p;
}
void creatList(queue& q, int n) {
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		nodeptr p = new node;
		p = creatnode(x);
		Push(q, p);
	}
}
void xuatList(queue q) {
	for (nodeptr k = q.front; k != NULL; k = k->link) {
		cout << k->data << " ";
	}
}
void deleteX(queue& q, int k) {
	nodeptr p = NULL;
	nodeptr s = q.front;
	while (s != NULL && s->data != k) {
		p = s;// p luôn sau s nếu tìm thấy k
		// vt s sẽ trùng với k
		s = s->link;
	}
	if (s == NULL) {// =>không tìm thấy k
		return;
	}
	if (p == NULL) {// k là node đầu tiên
		q.front = s->link; // cập nhật lại front
	}
	else {
		p->link = s->link;
	}
	if (s == q.rear) {// k là node cuối cùng
		q.rear = s;// cập nhật lại
	}
	delete s;
}
void xoaAllx(queue& q, int x) {
	queue Qt;
	khoitao(Qt);
	while (!isEmpty(q)) {
		nodeptr pt = Pop(q);
		if (pt->data != x) {
			Push(Qt, pt);
		}
		else {
			deleteX(q, pt->data);
		}
	}
	while (!isEmpty(Qt)) {
		nodeptr pt = Pop(Qt);
		Push(q, pt);
	}
}
int demX(queue q, int x) {
	int dem = 0;
	for (nodeptr k = q.front; k != NULL; k = k->link) {
		if (k->data == x) {
			dem++;
		}
	}
	return dem;
}
void xoaQueue(queue& q) {
	while (!isEmpty(q)) {
		nodeptr p = Pop(q);
		delete p;
	}
	q.front = NULL;
	q.rear = NULL;
}
void xoaXcuoi(queue& q, int x) {
	queue Qt; khoitao(Qt);
	queue Q; khoitao(Q);
	int dem = 0, flag = 0;
	for (nodeptr k = q.front; k != NULL; k = k->link) {
		if (k->data == x) {
			dem++;
		}
	}
	while (!isEmpty(q)) {
		nodeptr p = Pop(q);
		if (p->data == x) {
			flag++;
			if (flag == dem) {
				Push(Q, p);
			}
			else {
				Push(Qt, p);
			}
		}
		else {
			Push(Qt, p);
		}
	}
	while (!isEmpty(Qt)) {
		nodeptr pt = Pop(Qt);
		Push(q, pt);
	}
	xoaQueue(Q);
}
void xoaXthu2(queue& q, int x) {
	queue Qt; khoitao(Qt);
	int flag = 0;
	queue Q; khoitao(Q);
	while (!isEmpty(q)) {
		nodeptr p = Pop(q);
		if (p->data == x) {
			flag++;
			if (flag == 2) {
				Push(Q, p);
			}
			else {
				Push(Qt, p);
			}
		}
		else {
			Push(Qt, p);
		}
	}
	while (!isEmpty(Qt)) {
		nodeptr pt = Pop(Qt);
		Push(q, pt);
	}
	xoaQueue(Q);
}
void chenX(queue& q, int x, int y) {
	queue Qt;
	khoitao(Qt);
	nodeptr p = creatnode(y);

	while (!isEmpty(q)) {
		nodeptr k = Pop(q);
		if (k->data != x) {
			Push(Qt, k);
		}
		else {
			nodeptr h = creatnode(p->data);
			Push(Qt, k);
			Push(Qt, h);
		}
	}
	while (!isEmpty(Qt)) {
		nodeptr k = Pop(Qt);
		Push(q, k); // Đưa từng nút từ hàng đợi tạm trở lại q
	}
}
void chenXtang(queue& q, int x) {
	queue Qt; khoitao(Qt);
	nodeptr p = creatnode(x);
	while (!isEmpty(q)) {
		nodeptr k = Pop(q);
		if (k->data <= p->data) {
			Push(Qt, k);
		}
		else {
			Push(Qt, p);
			Push(Qt, k);
			break;
		}
	}
	while (!isEmpty(q)) {
		nodeptr k = Pop(q);
		Push(Qt, k);
	}

	while (!isEmpty(Qt)) {
		nodeptr pt = Pop(Qt);
		Push(q, pt);
	}
}
void tronQ1Q2Tang(queue& q1, queue& q2) {
	queue q;
	khoitao(q);
	while (!isEmpty(q1) && !isEmpty(q2)) {
		nodeptr s1 = Pop(q1);
		nodeptr s2 = Pop(q2);
		if (s1 > s2) {
			Push(q, s2);
			Push(q, s1);
		}
		else {
			Push(q, s1);
			Push(q, s2);
		}
	}
	while (!isEmpty(q1)) {
		nodeptr pt = Pop(q1);
		Push(q, pt);
	}
	while (!isEmpty(q2)) {
		nodeptr pt = Pop(q2);
		Push(q, pt);
	}
	xuatList(q);
}
void tachChanLe(queue& q) {
	queue q1, q2;
	khoitao(q1); khoitao(q2);
	while (!isEmpty(q)) {
		nodeptr pt = Pop(q);
		if (pt->data % 2 == 0) {
			Push(q1, pt);
		}
		else {
			Push(q2, pt);
		}
	}
	cout << "\n danh sach Q1: " << endl;
	xuatList(q1);
	cout << "\n danh sach Q2: " << endl;
	xuatList(q2);
}
void noiQ1voaQ2(queue& q1, queue& q2) {
	while (!isEmpty(q1)) {
		nodeptr pt = Pop(q1);
		Push(q2, pt);
	}
	cout << "\n danh sach sau khi noi: ";
	xuatList(q2);
}
int main() {
	queue a;
	khoitao(a);
	queue a1; khoitao(a1);
	queue a2; khoitao(a2);
	creatList(a1, 3);
	cout << "\n ==========" << endl;
	creatList(a2, 4);
	/*deleteX(a, 2);
	cout << "\n danh sach sau khi xoa!";*/
	cout << endl;
	tronQ1Q2Tang(a1, a2);
	return 0;
}