#include<iostream>
using namespace std;
class matrix
{
	int ma,ma1,count0,count1,ro,co;
	int m[10][10],v[10][10];
	public:
		matrix()
		{
			ma=0;ma1=0;count0=0;count1=0;
			cout << "enter the value of rows and column " << endl;
			cin >> ro >> co;
			if(ro>10||co>10)
			{
				printf("\nMatrix coloumn or row more than 10 not possible");
				exit(0);
			}
			else
			{
				cout << "enter the elements of matrix(0 and 1 only)="<< endl;
				for(int i=0;i<ro;i++)
					for(int j=0;j<co;j++)
					{
						v[i][j]=1; 
						cin >> m[i][j];
						/*if(m[i][j]!=0||m[i][j]!=1)
						{
							printf("\nNumbers should be binary only 0 or 1 only");
							exit(0);
						}*/
					}
			}
		}
		inline int dotask(int i,int j,int count,int t)
		{	
			count++;
			v[i][j]=0;
			if(t==1)
			{	
				if(count > ma)
					 ma=count;
			}
			else
			{
				if(count > ma1)
					ma1=count;
			}
			return count;
		}
		void path(int a,int i,int j,int count,int t)
		{
			if(t==1)
				if(ma==count1)
					return;
			if(t==0)
				if(ma1==count0)
					return;	
			if(i>=0 && j>=0 && i<ro && j<co)
			{
				//cout << a << i << j << count << endl;
				if(m[i][++j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{
					count=dotask(i,j,count,t);
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					j--;
					count--;
				}
				else
					j--;
				if(m[i][--j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{
					count=dotask(i,j,count,t);
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					j++;
					count--;
				}
				else
					j++;
				if(m[++i][j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{	
					count=dotask(i,j,count,t);
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					i--;
					count--;
				}
				else
					i--;
				if(m[--i][j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{
					count=dotask(i,j,count,t);
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					i++;
					count--;
				}
				else
					i++;
				if(m[++i][++j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{
					count=dotask(i,j,count,t);
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					i--;j--;
					count--;
				}
				else
				{
					i--;
					j--;
				}
				if(m[--i][--j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{
					count=dotask(i,j,count,t);
					v[i][j]=0;//cout << "calli6" << endl;
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					i++;
					j++;
					count--;
				}
				else
				{
					i++;
					j++;
				}
				if(m[--i][++j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{
					count=dotask(i,j,count,t);
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					i++;j--;
					count--;
				}
				else
				{
					i++;
					j--;
				}
				if(m[++i][--j]==t && v[i][j]==1 && i>=0 && j>=0 && i<ro && j<co)
				{
					count=dotask(i,j,count,t);
					path(m[i][j],i,j,count,t);
					v[i][j]=1;
					i--;j++;
					count--;
				}
				else
				{
					i--;
					j++;
				}
				//cout << ma << endl;
			}
		}
		void findpath()
		{
			for(int x=0;x<ro;x++)
				for(int y=0;y<co;y++)
				{
					if(m[x][y]==1)
						count1++;
					if(m[x][y]==0)
						count0++;
				}
			for(int l=0;l<ro;l++)
			{
				for(int k=0;k<co;k++)
				{
					for(int q=0;q<ro;q++)
					{
						for(int w=0;w<co;w++)
						{
				 			v[q][w]=1;	
						}
					}
					if(m[l][k]==1)
					{
						if(ma==0)
							ma++;
						v[l][k]=0;
						path(m[l][k],l,k,1,1);
					}
					else
					{
						if(ma1==0)
							ma1++;
						v[l][k]=0;
						path(m[l][k],l,k,1,0);
					}
				}
			}	
		}
		void display()
		{
			cout << "\nPath for 1 is " << ma << "\npath for 0 is " << ma1;
		}
};
int main()
{
	matrix m1;
	m1.findpath();
	m1.display();
	return 0;
}
