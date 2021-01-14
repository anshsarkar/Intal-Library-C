#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Returns the sum of two intals.
static char* remove_zeros(char* str)
{
	int m = strlen(str);
	int i;
	for(i=0; i<m; ++i)
	{
		if(str[i]!='0')
			break;
	}
	for(int j = i; j<m; ++j)	
		str[j-i] = str[j];
	str[m-i] = '\0';
	return str;
}

char* intal_add(const char* intal1, const char* intal2)
{
	if(strcmp(intal1, "0")==0 && strcmp(intal2, "0")==0)
	{
		char* res = malloc(sizeof(char)*2);
		strcpy(res, "0");
		return res;
	}
	int m = strlen(intal1); 
    int n = strlen(intal2);
	int max = m>n?m:n;
	char* result = (char*)malloc(sizeof(char)*(max+2));
	for(int i=0; i<max+2; ++i)
		result[i]='0';
	result[max+1]='\0';
	int k = max, c = 0, t, i, j;
	for(i = m-1, j = n-1; i >= 0 && j >= 0; --i, --j)
	{
		t = (intal1[i]-'0')+(intal2[j]-'0')+c;
		result[k--] = (char)(t%10+'0');
		c = t/10;
	}
	if(i==-1&&j!=-1)
	{
		while(k!=0)
		{
			t = (intal2[j--]-'0') + c;
			result[k--] = (char)(t%10+'0');
			c = t/10;
		}
	}
	else if(j==-1 && i!=-1)
	{
		while(k!=0)
		{
			t = (intal1[i--]-'0') + c;
			result[k--] = (char)(t%10+'0');
			c = t/10;
		}
	}
	if(c!=0)
		result[0]=((result[0]-'0')+c)+'0';
	result = remove_zeros(result);
	return result;
}

int intal_compare(const char* intal1, const char* intal2)
{
    int m,n;
    m = strlen(intal1);
    n = strlen(intal2);
    if(m>n)
      return 1;
    else if(n>m)
      return -1;
    else
    {
        for(int i = 0;i<m;++i)
        {
            if(intal1[i] > intal2[i])
              return 1;
            else if(intal1[i] < intal2[i])
              return -1;
        }
        return 0;
    }
    
}

char* intal_diff(const char* intal1, const char* intal2)
{
	char* diff=malloc(2*sizeof(char));
	strcpy(diff, "0");
	int m = strlen(intal1);
    int n = strlen(intal2);
	int max = m>n?m:n;
	int k = max-1;
	int comp = intal_compare(intal1, intal2);
	if(comp==0)
		return diff;
	free(diff);
	char* result = malloc(sizeof(int)*(max+1));
	char* intal1_cpy=malloc(m*sizeof(char));
	char* intal2_cpy = malloc(n*sizeof(char));
	strcpy(intal1_cpy, intal1);
	strcpy(intal2_cpy, intal2);
	result[max]='\0';
	if(comp==1) //intal1 > intal2
	{	
		int i, j;
		for(i=m-1, j=n-1; i>=0 && j>=0; --i, --j)
		{
			if(intal1_cpy[i] >= intal2_cpy[j])
				result[k--] = intal1_cpy[i] - intal2_cpy[j] + '0';
			else
			{
				if(intal1_cpy[i-1]!='0') 
					intal1_cpy[i-1]-=1;
				else
				{
					int k1=i-1;
					while(intal1_cpy[k1]=='0')
					{
						intal1_cpy[k1]='9';
						k1--;
					}
					intal1_cpy[k1]-=1;
				}
				result[k--] = (10 + (intal1_cpy[i]-'0')) - (intal2_cpy[j] -'0') + '0';
			}
		}
		if(i!=-1)
		{
			for(int k=i; k>=0; k--)
				result[k] = intal1_cpy[k];
		}
		free(intal1_cpy);
		free(intal2_cpy);
		result = remove_zeros(result);
		return result;
	}
	else
	{
		int i, j;
		for(i=n-1, j=m-1; i>=0 && j>=0; --i, --j)
		{
			if(intal2_cpy[i] >= intal1_cpy[j])
				result[k--] = intal2_cpy[i] - intal1_cpy[j] + '0';
			else
			{
				if(intal2_cpy[i-1]!='0') 
					intal2_cpy[i-1]-=1;
				else
				{
					int k1=i-1;
					while(intal2_cpy[k1]=='0')
					{
						intal2_cpy[k1]='9';
						k1--;
					}
					intal2_cpy[k1]-=1;
				}
				result[k--] = (10 + (intal2_cpy[i]-'0')) - (intal1_cpy[j] -'0') + '0';
			}
		}
		if(i!=-1)
		{
			for(int k=i; k>=0; k--)
				result[k] = intal2_cpy[k];
		}
		free(intal1_cpy);
		free(intal2_cpy);
		result = remove_zeros(result);
		return result;
	}
}

// Returns the product of two intals.
char* intal_multiply(const char* intal1, const char* intal2)
{
	if(strcmp(intal1, "0")==0 || strcmp(intal2, "0")==0)
	{
		char* res = malloc(sizeof(char)*2);
		strcpy(res, "0");
		return res;
	}
	char* temp = malloc(sizeof(char)*1001);
	int l1 = strlen(intal1);
    int l2 = strlen(intal2);
	char* result = malloc(sizeof(char)*(l1+l2+1));
	for(int i=0; i<1000; ++i)
		temp[i]='0';
	temp[1000]='\0';
	strcpy(result, "0");
	int k = l1+l2-1;
    int c=0;
	for(int i=l2-1; i>=0; --i)
	{
		k = l1;
		for(int j=l1-1; j>=0; --j)
		{
			int v = (intal1[j]-'0')*(intal2[i]-'0')+c;
			temp[k+i] = (char)(v%10 + '0');
			k--;
			c = v/10;
		}
		temp[i] = c+'0';
		temp[l1+l2] = '\0';
		char* add = intal_add(result, temp);
		strcpy(result, add);
		free(add);
		for(int i=0; i<1001; ++i)
			temp[i]='0';
		c=0;
	}
	free(temp);
	return result;
}

// Returns intal1 mod intal2
// The mod value should be in the range [0, intal2 - 1].
// intal2 > 1
// Implement a O(log intal1) time taking algorithm.
// O(intal1 / intal2) time taking algorithm may exceed time limit.
// O(intal1 / intal2) algorithm may repeatedly subtract intal2 from intal1.
// That will take intal1/intal2 iterations.
// You need to design a O(log intal1) time taking algorithm.
static char* dif(char* intal1,char* intal2)
{
	char* mod=intal2;
	char* a;
	char* s=(char*)malloc(sizeof(char)*1001);
	strcpy(s,intal1);
	while(intal_compare(s,mod)!=-1)
	{						
		a=intal_diff(s,mod);
		strcpy(s,a);
		free(a);		
	}
	return s;
}




char* intal_mod(const char* intal1, const char* intal2)
{
	char* intal2_cpy=(char*)malloc(sizeof(char)*1001);
	char* intal1_cpy=(char*)malloc(sizeof(char)*1001);
	strcpy(intal1_cpy,intal1);		
	strcpy(intal2_cpy,intal2);
	char* mod=(char*)malloc(sizeof(char)*1001);	
	mod[0]='0';
    mod[1]='\0';		
	if(strcmp(intal1,"0")==0)
	{
		free(intal1_cpy);
		free(intal2_cpy);
	    return mod;
	}
	char *t1,*t2;
	for(int i=0;i<strlen(intal1);i++)	
	{	
		char* i1=(char*)malloc(sizeof(char)*1001);
		char* i2=(char*)malloc(sizeof(char)*1001);
		char* t=(char*)malloc(sizeof(char)*2);
		t[0]=intal1[i];		
		t[1]='\0';
		strcpy(i1,mod);			
		if(strcmp(i1,"0")!=0)
			strcat(i1,"0");			
		t1=intal_add(i1,t);
		strcpy(i2,t1);
		t2=dif(i2,intal2_cpy);
		strcpy(mod,t2);
		free(t1);
		free(t2);
		free(i1);
		free(i2);
		free(t);
		if(strcmp(mod,intal2_cpy)==0)
			strcpy(mod,"0");
	}
	free(intal1_cpy);	
	free(intal2_cpy);	
	return mod;	
}

// Returns intal1 ^ intal2.
// Let 0 ^ n = 0, where n is an intal.
// Implement a O(log n) intal multiplications algorithm.
// 2^3000 has less than 1000 decimal digits. 3000 intal multiplications may exceed time limit.
char* intal_pow(const char* intal1, unsigned int n)
{
    char* result = (char*)calloc(1001, sizeof(char));
	char* val = (char*)calloc(1001, sizeof(char));
	result[1000] = '\0';
	val[1000] = '\0';

	char* temp;
	strcpy(val, intal1);
	strcpy(result, "1");

    while (n > 0) { 
        if (n & 1)  
        {
			temp = intal_multiply(result, val);
			strcpy(result, temp);
			free(temp);
		}
        n = n >> 1;
		if(n!=0)
		{
			temp = intal_multiply(val, val); 
			strcpy(val, temp);
			free(temp);
		}
    } 
	free(val);
	return result;
} 

// Returns Greatest Common Devisor of intal1 and intal2.
// Let GCD be "0" if both intal1 and intal2 are "0" even though it is undefined, mathematically.
// Use Euclid's theorem to not exceed the time limit.
char* intal_gcd(const char* intal1, const char* intal2)
{	
	char* intal2_cpy=(char*)malloc(sizeof(char)*1001);
	char* intal1_cpy=(char*)malloc(sizeof(char)*1001);
	strcpy(intal2_cpy,intal2);	
	strcpy(intal1_cpy,intal1);
	char* a;
	while((!strcmp(intal2_cpy,"0")) == 0)
	{
		a=intal_mod(intal1_cpy,intal2_cpy);	
		strcpy(intal1_cpy,intal2_cpy);		
		strcpy(intal2_cpy,a);		
		free(a);	
	}
	free(intal2_cpy);
	return intal1_cpy;
}

// Returns nth fibonacci number.
// intal_fibonacci(0) = intal "0".
// intal_fibonacci(1) = intal "1".
char* intal_fibonacci(unsigned int n)
{
    char* l1 = (char*)calloc(2, sizeof(char)); 
    l1[0] = 48;
    char* l2 = (char*)calloc(2, sizeof(char)); 
    l2[0] = 49;
    if(n==0)
    {
        free(l2);
        return l1;
    }
    else
    {
        char *temp;
        for(int i=2;i<=n;++i)
        {
            temp = intal_add(l1,l2);
            free(l1);
            l1 = l2;
            l2 = temp;
        }
        
    }
    free(l1);
    return l2;
    
}

// Returns the factorial of n.
char* intal_factorial(unsigned int n)
{
    char* i1 = (char*)calloc(2, sizeof(char)); 
    strcpy(i1, "1");
    char* mul = (char*)calloc(2, sizeof(char)); 
    strcpy(mul, "1");    
    char* temp;    
    for(int i=2; i<=n; ++i)
    {
        temp = intal_add(mul, "1");
        free(mul);
        mul = temp;
        temp = intal_multiply(i1, mul);
        free(i1);
        i1 = temp;
    }
    free(mul);
    return i1;    
}


// Returns the Binomial Coefficient C(n,k).
// 0 <= k <= n
// C(n,k) < 10^1000 because the returning value is expected to be less than 10^1000.
// Use the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1)
// Make sure the intermediate intal values do not cross C(n,k).
// Use Dynamic Programming. Use extra space of not more than O(k) number of intals. Do not allocate the whole O(nk) DP table.
// Don't let C(1000,900) take more time than C(1000,500). Time limit may exceed otherwise.
char* intal_bincoeff(unsigned int n, unsigned int k)
{ 
	if(k > n-k)
		k = n-k; 
	char** dp = (char**)malloc(sizeof(char*)*(k+1));

	for(int i=0; i < k+1; i++)
	{
		dp[i] = (char*)calloc(1001, sizeof(char));
		strcpy(dp[i], "0");
	}
	strcpy(dp[0], "1"); 

	char* t;
	for (int i=1; i <= n; i++) 
	{
		int j = i<k ?i:k;
		for (;j > 0; j--) 
		{
			t = intal_add(dp[j], dp[j-1]); 
			strcpy(dp[j], t);
			free(t);
		}
	}

	char* final = (char*)calloc(1001, sizeof(char));
	strcpy(final, dp[k]);

	for(int i=0; i<k+1;i++)
		free(dp[i]);
	free(dp);
	return final;
} 

// Returns the offset of the largest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_max(char **arr, int n)
{
    int index = 0;
    for(int i=1; i<n; ++i)
    {
        if(intal_compare(arr[i], arr[index]) > 0)
        {
            index = i;    
        }            
    }        
    return index;
}

// Returns the offset of the smallest intal in the array.
// Return the smallest offset if there are multiple occurrences.
// 1 <= n <= 1000
int intal_min(char **arr, int n)
{
    int index = 0;
    for(int i=1; i<n; ++i)
    {
        if(intal_compare(arr[i], arr[index]) < 0)
        {
            index = i;
        }            
    }          
    return index;
}

// Returns the offset of the first occurrence of the key intal in the array.
// Returns -1 if the key is not found.
// 1 <= n <= 1000
int intal_search(char **arr, int n, const char* key)
{
    for(int i=0; i<n; ++i)
    {
        if(intal_compare(arr[i], key) == 0)
        {
            return i;
        }            
    }        
    return -1;
}

// Returns the offset of the first occurrence of the key intal in the SORTED array.
// Returns -1 if the key is not found.
// The array is sorted in nondecreasing order.
// 1 <= n <= 1000
// The implementation should be a O(log n) algorithm.
int intal_binsearch(char **arr, int n, const char* key)
{
	int start = 0, end = n-1;
	int mid;
	int result = -1;
	while(start<=end)
	{	
		mid = (start+end)/2;
		if(intal_compare(key, arr[mid])==0)
		{
			result = mid;
			end = mid -1;
		}
		if(intal_compare(key, arr[mid])==1)
			start = mid+1;
		else
			end = mid-1;
	}
	return result;
}

// Sorts the array of n intals.
// 1 <= n <= 1000
// The implementation should be a O(n log n) algorithm.
static void merge(char**arr,int l,int r,int mid,int n)
{
    char**L=(char**)calloc(1001,sizeof(char*));
    for(int i=0;i<1000;i++)
    {
        L[i]=(char*)calloc(1001,sizeof(char*));
        memset(L[i],'0',1000);
        L[i][1000] = '\0';
    }
    char**R=(char**)calloc(1001,sizeof(char*));
    for(int i=0;i<1000;i++)
    {
        R[i]=(char*)calloc(1001,sizeof(char*));
        memset(R[i],'0',1000);
        R[i][1000] = '\0';
    }
    for(int i=0;i<mid-l+1;i++)
    {
        strcpy(L[i],arr[l+i]);
    }
    for(int j=0;j<r-mid;j++)
    {
        strcpy(R[j],arr[mid+j+1]);
    }
    int k1=l;
    int i1=0;
    int j1=0;
    while(i1<mid-l+1 && j1<r-mid)
    {
        if(intal_compare(L[i1],R[j1])==-1)
        {
            strcpy(arr[k1],L[i1]);
            k1+=1;
            i1+=1;
        }
        else{
              strcpy(arr[k1],R[j1]);
              j1+=1;
              k1+=1;
        }
    }
    if(i1<mid-l+1)
    {
        while(i1<mid-l+1)
        {
            strcpy(arr[k1],L[i1]);
            k1+=1;
            i1+=1;
        }
    }
    if(j1<r-mid)
    {
        while(j1<r-mid)
        {
            strcpy(arr[k1],R[j1]);
            k1+=1;
            j1+=1;
        }
    }
    for(int i=0;i<1000;i++)
    {
        free(L[i]);
        free(R[i]);
    }
    free(L);
    free(R);
}
static void merge_sort(char**arr,int l,int r,int n)
{
    if(l<r)
    {
    int mid=(l+r)/2;
    merge_sort(arr,l,mid,n);
    merge_sort(arr,mid+1,r,n);
    merge(arr,l,r,mid,n);
    }
}
void intal_sort(char **arr, int n)
{
        merge_sort(arr,0,n-1,n);
}

// Coin-Row Problem - Dynamic Programming Solution
// There is a row of n coins whose values are some positive integers C[0..n-1].
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
// 1 <= n <= 1000
// The implementation should be O(n) time and O(1) extra space even though the DP table may be of O(n) size.
// Eg: Coins = [10, 2, 4, 6, 3, 9, 5] returns 25

static char* max(char* intal1,char* intal2)
{
    if(intal_compare(intal1, intal2)==1)
    {
        return intal1;
    }
    else
    {
        return intal2;
    }
}
char* coin_row_problem(char **arr, int n)
{
	char *i_1, *i_2, *ans, * temp, *temp1;
	if(n==0)
	{
		char* temp = malloc(sizeof(char)*2);
		strcpy(temp, "0");
		return temp;
	}
	else if(n==1)
	{
		char* temp = malloc(sizeof(char)*1001);
		strcpy(temp, arr[0]);
		return temp;
	}
	else if(n==2)
	{
		temp = max(arr[0], arr[1]);
		return temp;
	}
	else
	{
		i_2 = malloc(sizeof(char)*1001);
		i_1 = malloc(sizeof(char)*1001);
		ans = malloc(sizeof(char)*1001);
		strcpy(i_2, "0"); //F[0] = 0
		strcpy(i_1, arr[0]); //F[1] = arr[1]
		for(int i=2; i<=n; ++i)
		{
			temp = intal_add(arr[i-1], i_2);
			temp1 = max(temp, i_1);
			strcpy(ans, temp1);
			strcpy(i_2, i_1);
			strcpy(i_1, temp1);
			free(temp);
		}
	}
	free(i_2);
	free(i_1);
	return ans;
}