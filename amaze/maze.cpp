/* 
maze.cpp

Author: Karime Maamari

Short description of this file:
I'd just like to apologize in advance for the excessive commenting. It's really
moreso for myself to understand my code when I look back at it, so I apologize 
if it's a bit much.
*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

int maze_search(char**, int, int);                     //Prototypes
int solution(Location,Location**,char**maze, int);

int main() {

   int rows, cols;                                     //total rows and cols
   cin >> rows >> cols;                                //input rows & cols
   char** maze;                                        //pntr to pntr to maze
   maze = read_maze(&rows, &cols);                     //allocated 2D array
   int valid = maze_search(maze, rows, cols);          //result of search
   

   if (maze == 0) {                                    //checks input format
      cout << "Error, input format incorrect" << endl;
      return 1;
   }


   if (valid == 1) {                                   //successful maze
      print_maze(maze, rows, cols);
   }
   else if (valid == 0) {                              //blocked off maze
      cout << "No path could be found!" << endl;
   }
   else {
      cout << "Invalid maze." << endl;                 //invalid components
   }


   for(int r = 0; r < rows; r++){                      //deallocate
      delete [] maze[r];
   }
   delete [] maze;

   return 0;
}

int maze_search(char** maze, int rows, int cols) {

   Location s, f;                                      //start/finish locations
   Queue q = Queue(rows*cols);                         //arr for queue
   int starFound = 0;                                  //start found?
   int finFound = 0;                                   //finish found?
   bool done = false;                                  //are we done?!

   for(int r = 0; r < rows; r++){                      //look for start and fin
      for(int c = 0; c < cols; c++){
         if(maze[r][c] == 'S'){
            s.row = r;
            s.col = c;
            starFound++;
         }
         else if(maze[r][c] == 'F'){
            f.row = r;
            f.col = c;
            finFound++;
         }
      }
   }

   if(starFound != 1 || finFound != 1){                //s or f missing 
      return -1;
   }

   bool** visited = new bool*[rows];                   //arr for visited
   for(int r = 0; r < rows; r++){
      visited[r] = new bool[cols];                     
   }
   for(int r = 0; r < rows; r++){                      //initialize arr to 0
      for(int c = 0; c < cols; c++){
         visited[r][c] = false;
      }
   }

   Location** prev = new Location*[rows];              //arr for prev 
   for(int r = 0; r < rows; r++){
      prev[r] = new Location[cols];                    
   }

   q.add_to_back(s);                                   //add start to queue

   while(!q.is_empty() && !done){                      
      Location curr = q.remove_from_front();           //curr is front of queue

      Location n, so, e, w;
         n.col = curr.col - 1;                         //n = (x, y+1)
         n.row = curr.row;
         so.col = curr.col + 1;                        //s = (x, y-1)
         so.row = curr.row;
         e.col = curr.col;                             //e = (x+1, y)
         e.row = curr.row + 1;
         w.col = curr.col;                             //w = (x-1, y)
         w.row = curr.row - 1;
      Location border[4] = {n, so, e, w};              

      for(int dir = 0; dir < 4; dir++){                //traverse n, s, e, w
         int dRow = border[dir].row;
         int dCol = border[dir].col;

         if(dRow < rows && dCol < cols                 //boundary check
            && dRow >= 0 && dCol >= 0)
         {
            if(maze[dRow][dCol] == '.' &&              //unvisited and unmarked
               !visited[dRow][dCol])
            {
               q.add_to_back(border[dir]);             //add current to queue
               visited[dRow][dCol] = true;             //mark as visited
               prev[dRow][dCol] = curr;                //place in prev array
            }
            else if(maze[dRow][dCol] == 'F')           //if at endpoint
            {
               visited[dRow][dCol] = true;             //same as above
               prev[dRow][dCol] = curr;                
               done = true;                            
               break;                                  
            }
         }
      }
   }

   if(done){                                           //if found finish  
      solution(prev[f.row][f.col], prev, maze, rows);  //trace back
   }
   

   for(int r = 0; r < rows; r++) {                     //delete internal arrs
      delete [] visited[r];
      delete [] prev[r];
   }
   delete [] visited;                                  //delete external arrs
   delete [] prev;

   return done;                                        //return done val
}

int solution(Location curr, Location** prev, char** maze,int rows) {
   if(maze[curr.row][curr.col] == 'S') {               //if at start, exit
      return 1;
   }
   else {                                              //otherwise plot path
      maze[curr.row][curr.col] = '*';
      return solution(prev[curr.row][curr.col], prev, maze, rows);
   }
}
