CSCI 103 Programming Assignment, ChromaKey, Fall 2017

Name: Karime Maamari

Email Address: maamari@usc.edu

=============================== Prelab =======================================

Pixel                |    RGB Value     |  Distance from Chroma Key
-------------------------------------------------------------------
Top-left background  | (71, 139, 20)    |  n/a
Arm                  | (27, 30, 28)     |  117.817
Vest                 | (251, 217, 242)  |  296.256
Shirt                | (235, 210, 230)  |  275.748


================================== Review ===================================

Response 1:
To find the average background value for method one, I took a 3 by 3 square 
from each corner and took the average of those values to find a suitable 
average background value. I chose 3 by 3 because I felt as though that size
is large enough of a variation to allow a valid average value without being
too large and hence allowing too much variation.

	
Response 2:

  Image                  Min Threshold           Max Threshold
  Colbert range:  from   55               to     85
  Bird range:     from   45               to 	 95


3. For method 2, explain what you implemented and why.  How did you go about 
implementing it? Walk us through a high-level description of what you did in 
your code (and use comments in the actual .cpp file to fill in the details). 
What other alternatives did you consider either before or after you
implemented your selected method?  What are the relative pros and cons of 
these methods? [This question is open-ended!]


Response 3:

For method two, I set the initial pixel's mask to false because it should be
the chromakey pixel and I can't compare it against itself. Then, I traversed
the inImage array, finding the distance between each pixel and the chromakey
pixel -- this difference was then stored into difArr. Basically, I was
looking to see if the distance of the pixel I was checking was within 40 of
the distance from the chromakey to the previous pixel (n-1). If it was, I 
stored this distance into difArr and placed this pixel as the chromakey and 
set the mask value to 0. If it wasn't, I set the pixel to the foreground 
and set the mask value to 1. 

One thing I considered was using a wider range of pixel for the average RGB 
value, but that would run the risk of pulling variable pixels that would screw 
with the value, so I decided better safe than sorry.
