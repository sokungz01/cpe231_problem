#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coordinate
{
    double x;
    double y;
};

void printArr(struct coordinate *arr, int size);
double BruteForceSmallestDistance(struct coordinate *arr, int size);
double ClosetPair(struct coordinate *pos, int size);
void swap(struct coordinate *a, struct coordinate *b);
int Partition(struct coordinate *arr, int l, int r);
void QuickSort(struct coordinate *arr, int l, int r);
double min(double a, double y);
double dist(struct coordinate pos1, struct coordinate pos2);

int main()
{
    int n;
    scanf("%d", &n);
    struct coordinate *pos = calloc(n,sizeof(struct coordinate));
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &pos[i].x, &pos[i].y);
    }
    QuickSort(pos, 0, n - 1);
    printf("%.4lf",ClosetPair(pos,n));
    free(pos);
    return 0;
}

void printArr(struct coordinate *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%lf %lf\n", arr[i].x, arr[i].y);
    }
    printf("\n");
}

double BruteForceSmallestDistance(struct coordinate *arr, int size)
{
    double min = dist(arr[0],arr[1]);
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            double temp = dist(arr[i],arr[j]);
            if (temp < min)
                min = temp;
        }
    }
    return min;
}

double ClosetPair(struct coordinate *arr, int size)
{   
    if (size <= 3)
       return BruteForceSmallestDistance(arr, size);
    int mid = size/2;

    double delta1 = ClosetPair(arr,mid);
    double delta2 = ClosetPair(&arr[mid],size-mid);

    double delta = min(delta1,delta2);

    double minimum = dist(arr[0],arr[1]);
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
           if(arr[j].x-arr[i].x < delta){
            if(fabs(arr[i].y-arr[j].y) < delta){
                minimum = min(minimum,dist(arr[i],arr[j]));
            }
           }
           else{
            break;
           }
        }
    }

    return min(delta, minimum);
}

void swap(struct coordinate *a, struct coordinate *b)
{
	double tempx_i = a->x;
	double tempy_i = a->y;
	(a->x) = b->x;
	(a->y) = b->y;
	(b->x) = tempx_i;
	(b->y) = tempy_i;
}

int Partition(struct coordinate *arr, int l, int r)
{	int s  = l;
	int i = 0;
	double pivot = arr[l].x;
	for(i = l+1; i <= r;i++){
		if((arr[i].x) < pivot){
			s++;
			swap(&arr[i],&arr[s]);
		}
	}
	
	swap(&arr[l],&arr[s]);
	return s;
}

void QuickSort(struct coordinate *arr, int l, int r)
{
    if (l < r)
    {
        int s = Partition(arr, l, r);
        QuickSort(arr, l, s - 1);
        QuickSort(arr, s + 1, r);
    }
}

double min (double a, double b)
{
    return a < b ? a : b;
}

double dist(struct coordinate pos1, struct coordinate pos2){
    double diffPosX = pos1.x-pos2.x;
    double diffPosY = pos1.y-pos2.y;    
    return sqrt(pow(diffPosX,2)+pow(diffPosY,2));
}
