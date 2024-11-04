#include <iostream>

using namespace std;

int bay(int nums[],int keys,int l,int r){
    while(l<=r){
    int mid=(l+r)/2;
    if(nums[mid]<keys){
        l=mid+1;
    }
    else{
        r=mid-1;
    }
    }
    return l;
}
void binaryinsertion(int nums[],int n){
    for (int i=1;i<n;i++){
    int keys=nums[i];
    int l=0;
    int r=i-1;
    int j=bay(nums,keys,l,r);
    for(int k=i;k>j;k--){
        nums[k]=nums[k-1];
    }
    nums[j]=keys;
}
}
bool binarySearch(int nums[],int n,int keys){
    int l=0;
    int r=n-1;
    while (l<r) {
        int mid=(l+r)/2;
        if (nums[mid] == keys){
            return true;
        }
        else if (nums[mid] < keys){
            l = mid+1;
        }
        else{
            r = mid;
        }
    }
    return false;
}
void bubbleSort(int nums[],int n){
    for(int i=n-1;i>=0;i--){
        for (int j=0;j<i;j++){
            if (nums[j]>nums[j+1]){
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
}
void insertionSort(int nums[],int n){
    for(int i=0;i<n;i++){
        for (int j=i;j>0;j--){
            if (nums[j-1]>nums[j]){
                int temp=nums[j];
                nums[j]=nums[j-1];
                nums[j-1]=temp;
            }
        }
    }
}
void simpleSort(int nums[],int n){
    for(int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if (nums[j]<nums[i]){
                int temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
            }
        }
    }
}
void selectionSort(int nums[],int n){
    for(int i=0;i<n-1;i++){
            int u=i;
        for (int j=i+1;j<n;j++){
            if (nums[j]<nums[u]){
                 u=j;
            }
        }
        if(i!=u){
                int temp=nums[i];
                nums[i]=nums[u];
                nums[u]=temp;
        }

    }
}
bool simpleSearch(int nums[],int n,int key){
    for(int i=0;i<n;i++){
        if(nums[i] == key){
            return true;
        }
    }
    return false;
}

int main() {
    while (true) {
        cout << "Main menu:\n";
        cout << "Enter 1 for sorting!\n";
        cout << "Enter 2 for searching!\n";
        cout << "Enter 3 to Exit the Main and leave!\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Sorting menu:\n";
            cout << "Enter 1 for simple sorting!\n";
            cout << "Enter 2 for bubble sorting!\n";
            cout << "Enter 3 for selection sorting!\n";
            cout << "Enter 4 for insertion sorting!\n";
            cout << "Enter 5 for binary insertion sorting!\n";

            int so;
            cin >> so;
            int n;
            cout<<"how many numbers would you want to enter: ";
            cin>>n;

            int nums[n];
            cout << "Enter the list of numbers you want to sort: ";
            for(int i=0;i<n;i++){
                cin>>nums[i];
            }

            switch (so) {
                case 1:
                    simpleSort(nums,n);
                    break;
                case 2:
                    bubbleSort(nums,n);
                    break;
                case 3:
                    selectionSort(nums,n);
                    break;
                case 4:
                    insertionSort(nums,n);
                    break;
                case 5:
                    binaryinsertion(nums,n);
                    break;
                default:
                    cout << "There is no solution for your choice!\n";
                    continue;
            }

            cout << "The sorted elements are: ";
            for (int i=0;i<n;i++) {
                cout << nums[i] << " ";
            }
            cout << endl;

        } else if (choice == 2) {
            cout << "Search menu:\n";
            cout << "Enter 1 for simple searching!\n";
            cout << "Enter 2 for binary searching!\n";
            int se;
            cin >> se;

            int n;
            cout<<"how many numbers would you want to enter: ";
            cin>>n;

            int nums[n];
            cout << "Enter the sorted list of numbers you want to search (end with -1): ";
            for(int i=0;i<n;i++){
                cin>>nums[i];
            }

            int keys;
            cout << "Your target number to find: ";
            cin >> keys;

            bool result;
            if (se == 1) {
                result = simpleSearch(nums, n,keys);
            } else if (se == 2) {
                result = binarySearch(nums,n, keys);
            } else {
                cout << "You have chosen the incorrect option!\n";
                continue;
            }

            cout << (result ? "Found" : "Not Found") << endl;

        } else if (choice == 3) {
            cout << "Terminating the Main! Goodbye!\n";
            break;
        } else {
            cout << "The choice you made was incorrect!\n";
        }
    }

    return 0;
}
