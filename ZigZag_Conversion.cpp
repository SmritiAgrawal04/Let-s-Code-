class Solution {
public:
    string convert(string s, int numRows) {
        int n= s.length()< numRows? s.length(): numRows;
        
        if(n==0 || n==1)
            return s;
        
        string result[n];
        
        for(int i=0 ; i< n; i++)
        {
            int j= i;
            string temp="";
            if(i== 0 || i== n-1)
            {
                // cout << "here" << endl;
                while(j < s.length())
                {
                    temp += s[j];
                    j +=(2*n)-2;
                }
            }
            else
            {
                while(j< s.length())
                {
                    temp+= s[j];
                    j += 2*(n-i-1);
                    if(j<s.length())
                        temp+= s[j];
                    j -= 2*(n-i-1);
                    j += 2*(n-1);
                }
            }
            result[i]=temp;
        }
        string final="";
        
        for(int i=0; i <n; i++)
            final += result[i];
        
        return final;
    }
};