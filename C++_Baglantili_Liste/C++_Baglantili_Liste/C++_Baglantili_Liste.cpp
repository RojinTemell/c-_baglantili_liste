#include<iostream>
using namespace std;

struct Node {
	int deger;
	Node* sonraki;
};

struct Liste {
	Node* bas;
	void olustur();
	void sonaEkle(Node*);
	void basaEkle(Node*);
	void ortayaEkle(Node*);
	void yazdir();
};

int main()
{
	Liste* l = new Liste();
	l->olustur();
	l->yazdir();

	Node* n = new Node();
	n->deger = 0;
	l->sonaEkle(n);
	l->yazdir();

	n = new Node();
	n->deger = 1;
	l->basaEkle(n);
	l->yazdir();

	n = new Node();
	n->deger = 2;
	l->ortayaEkle(n);
	l->yazdir();

	n = new Node();
	n->deger = 3;
	l->sonaEkle(n);
	l->yazdir();

	n = new Node();
	n->deger = 4;
	l->basaEkle(n);
	l->yazdir();

	n = new Node();
	n->deger = 5;
	l->ortayaEkle(n);
	l->yazdir();





	return 0;
}

void Liste::olustur() {
	bas = NULL;
}

void Liste::sonaEkle(Node* n) {
	if (bas == NULL) {
		bas = n;
		return;
	}
	Node* tara;
	tara = bas;
	while (tara->sonraki) {
		tara = tara->sonraki;
	}
	tara->sonraki = n;
}

void Liste::basaEkle(Node* n) {
	if (bas == NULL)
		bas = n;
	else {
		n->sonraki = bas;
		bas = n;
	}
}

void Liste::ortayaEkle(Node* n) {
	if (bas == NULL) {
		bas = n;
		return;
	}
	int dugumSayisi = 0;
	Node* tara;
	tara = bas;
	while (tara) {
		dugumSayisi++;
		tara = tara->sonraki;
	}
	tara = bas;
	for (int i = 0; i < dugumSayisi / 2 - 1;i++)
		tara = tara->sonraki;
	n->sonraki = tara->sonraki;
	tara->sonraki = n;
}

void Liste::yazdir() {
	Node* tara;
	tara = bas;
	if (!tara) {
		cout << "Liste bos!!!" << endl;
		return;
	}
	while (tara) {
		cout << tara->deger << " ";
		tara = tara->sonraki;
	}
	cout << endl;
}