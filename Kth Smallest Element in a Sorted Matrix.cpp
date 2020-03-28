/*Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.*/

class Point 
{ 
    int value; 
    int row;
    int col;
public: 
    Point(int _value, int _row, int _col) 
    { 
        value = _value; 
        row = _row; 
        col = _col;
    } 
    int get_value()  { return value; } 
    int get_row()  { return row; } 
    int get_col()  { return col; }  
}; 
  
class myComparator 
{ 
public: 
    int operator() (Point& p1, Point& p2) 
    { 
        return p1.get_value() > p2.get_value(); 
    } 
}; 

class Solution {
public:
    
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Point, vector<Point>, myComparator > pq;
        
        for (int i=0; i< matrix[0].size(); i++)
            pq.push(Point(matrix[0][i], 0, i));
        
    int result, r, c, ele;
        
 
        while(k>0)
        {
            Point P= pq.top();
            result= P.get_value();
            r= P.get_row();
            c= P.get_col();
            ele= r+1< matrix.size()? matrix[r+1][c]: INT_MAX;
            
            pq.pop();
            pq.push(Point(ele, r+1, c));
            
            k--;
        }
    return result;
    }
};