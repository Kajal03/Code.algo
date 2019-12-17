#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int sum=0,temp=0;
    for (int i=0;i<=3;i++)
        for(int j=0;i<=3;j++)
        {
            temp = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2] ;
            if(temp>sum)
                sum=temp;
        }

    return sum;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

    //    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    /*
    cout<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    int result = hourglassSum(arr);

    //fout << result << "\n";
    cout<<result;
    //fout.close();

    return 0;
}
