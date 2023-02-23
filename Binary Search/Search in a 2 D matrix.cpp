 public boolean searchMatrix(int[][] matrix, int target) {
         int low=0,high=matrix[0].length*matrix.length-1;
        
          while(low<=high)
          {
              int mid = low+(high-low)/2;
              
              int row=mid/matrix[0].length,coloumn=mid%matrix[0].length;
              
              if(matrix[row][coloumn]==target) return true;
              else if(matrix[row][coloumn]>target)
              {
                  high=mid-1;
              }
              else
              {
                 low=mid+1;   
              }
          }
        
        return false;
    }