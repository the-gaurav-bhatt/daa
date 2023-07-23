#include<stdio.h>
#include<string.h>
#define MAX 500
int t[MAX];

// This function prepares the shift table by calculating the shift distance for each character in the pattern
void shifttable(char p[])
{
 	int i,j,m;
	m=strlen(p);
 	for(i=0;i<MAX;i++)
 		 t[i]=m; // Initialize the shift table with the length of the pattern
 	for(j=0;j<m-1;j++)
 		t[p[j]]=m-1-j; // For each character in the pattern, calculate the shift distance
}

// This function implements the Horspool algorithm for pattern matching
int horspool(char txt[],char p[])
{
	 int i,j,k,m,n;
	 n=strlen(txt); // Length of the text
	 m=strlen(p); // Length of the pattern
	 printf("\nLength of text=%d",n);
	 printf("\n Length of pattern=%d",m);
	 i=m-1; // Start from the end of the pattern
 	while(i<n) // While the end of the pattern is within the text
 	{
 		k=0;
 		while((k<m)&&(p[m-1-k]==txt[i-k])) // While the characters match and we haven't reached the beginning of the pattern
  			k++; // Move towards the beginning of the pattern
  		if(k==m) // If we have reached the beginning of the pattern, it means we have found a match
 			return(i-m+1); // Return the starting position of the match
  		else
  			i+=t[txt[i]]; // If no match, shift the pattern according to the shift table
 	}
	return(-1); // If no match is found in the entire text, return -1
}

// The main function
int main()
{
 	char txt[100],p[100];
 	int pos;
 	printf("Enter the text in which pattern is to be searched:\n");
 	gets(txt);   // Get the text from the user
 	printf("Enter the pattern to be searched:\n");
 	gets(p);   // Get the pattern from the user
 	shifttable(p); // Prepare the shift table
 	pos=horspool(txt,p); // Search for the pattern in the text
 	if(pos>=0)
 		 printf("\n The desired pattern was found starting from position %d",pos+1); // If a match is found, print its position
	 else
 		 printf("\n The pattern was not found in the given text");
    return 0; // If no match is found, print a message
}
