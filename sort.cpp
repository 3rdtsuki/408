#include<iostream>
using namespace std;

void insertSort(int *a,int n) {
	int i=0,j=0;
	for(i=1; i<n; ++i) {
		int t=a[i];
		for(j=i-1; j>=0; --j) { //��a[i-1]������ǰ�Ҳ���λ�ã�һ����ǰԪ�ش��ڵ���ǰ���Ԫ�ؾ�ֹͣ
			if(a[j]>t) {
				a[j+1]=a[j];//���Ԫ�غ���
			} else break; //ֱ���ҵ�������t�ģ��˳�ѭ��
		}
		a[j+1]=t;
	}
}

void quickSort(int *a,int low,int high) {
	int i=low,j=high;
	if(i>=j)return;
	int t=a[i];//����
	while(i<j) {
		while(i<j&&a[j]>=t)j--;
		a[i]=a[j];//������С�ķŵ�ǰ��
		while(i<j&&a[i]<=t)i++;
		a[j]=a[i];//�������ķŵ�����
	}
	a[i]=t;//����ŵ���ȷ
	QuickSort(a,low,i-1);
	QuickSort(a,i+1,high);
}

void selectSort(int *a,int n) {
	for(int i=0; i<n-1; ++i) {
		int min_index=i;
		for(int j=i+1; j<n; ++j) {
			if(a[j]<a[min_index]) { //�Ƚ�
				min_index=j;
			}
		}
		if(i!=min_index) {
			swap(a[i],a[min_index]);//�ƶ�
		}
	}
}

void BubbleSort(int *a,int n) {
	for(int i=0; i<n; ++i) { //i����ǰԪ��
		bool swaped=false;
		for(int j=n-1; j>i; --j) { //ÿ�˰���СԪ�طŵ�i��
			if(a[j]<a[j-1]) {
				swap(a[j],a[j-1]);
				swaped=true;
			}
		}
		if(swaped==false) {
			break;
		}
	}
}

class HeapSort {
	public:
		void HeapAdjust(int *a,int k,int n) { //������Ϊk������ʹԪ��a[k]������ȷλ��
			int t=a[k];
			for(int i=2*k; i<=n; i*=2) {
				if(i<n&&a[i]<a[i+1]) {
					i++;
				}
				if(t>=a[i])break;
				else {
					a[k]=a[i];//������Ķ�������
					k=i;//��׹����Ϊ�滻����ʹ�����������������ʣ���Ҫ��������
				}
			}
			a[k]=t;//��t�ŵ�����λ��
		}
		void BuildMaxHeap(int *a,int n) { //����ԭʼһά���鹹������
			for(int i=n/2; i>0; --i) { //i������֧�ڵ�n/2��ʼ����
				HeapAdjust(a,i,n);
			}
		}

		void HeapSort(int *a,int n) { //ע������a[0]Ϊ�գ�����2*i�������
			BuildMaxHeap(a,n);
			for(int i=n; i>1; --i) {
				swap(a[1],a[i]);//���Ѷ�Ԫ�أ����Ԫ�أ��Ͷѵ�Ԫ�ؽ���
				HeapAdjust(a,1,i-1);//��ʣ��i-1��Ԫ�ص���������
			}
		}
};

class MergeSort {
	public:
		//��a[low,mid]��a[mid+1,high]�鲢
		void Merge(int *a,int low,int mid,int high) {
			int i,j,k;
			int b[200];
			for(i=low; i<=high; ++i) { //����b��Ϊ�����ռ�
				b[i]=a[i];
			}
			for(i=low,j=mid+1,k=i; i<=mid&&j<=high; ++k) {
				if(b[i]<b[j]) { //���Ͻ���СԪ�ظ��ƹ���
					a[k]=b[i++];
				} else {
					a[k]=b[j++];
				}
			}
			while(i<=mid) { //��ʣ��ĸ��ƹ���
				a[k++]=b[i++];
			}
			while(j<=mid) {
				a[k++]=b[j++];
			}
		}
		void MergeSort(int *a,int low,int high) {
			if(low<high) {
				int mid=(low+high)>>1;
				MergeSort(a,low,mid);//�Ƚ����ҷֱ��ź���
				MergeSort(a,mid+1,high);
				Merge(a,low,mid,high);//��·�鲢
			}
		}
};

int main() {
	int a[]= {49,38,65,97,76,13,27,49};
	int n=8;
	insertSort(a,n);
	for(int i=0; i<n; ++i) {
		cout<<a[i]<<' ';
	}

}
