  <h1> Convert Any File to Video: Visualize Your Data Like Never Before </h1>
  <br>
  <em><strong> Have you ever wondered how files are constructed, and what <br>
  makes up their binary code?. Have you ever thought about <br>
  what it would look like to convert any file into a video, pixel by pixel? </strong></em><br>
  <br>
  <strong><h> <a href="https://www.youtube.com/watch?v=GmMuY9nMn-c">Love Story - Taylor Swift but in binary ?</a></h></strong> <br>
  <br>
  <img src="https://user-images.githubusercontent.com/102965306/235337983-baa60836-3968-4ec3-b3e8-4e02c73126e5.gif" alt="">
  <br>
  <br>
  <em><strong> Look no further, this program does just that. With this <br>
  file-to-video converter, you can "see" your files in pretty much its raw form. <br>
  Each pixel is represented by a bit block for grayscale mode, <br>
  or 3 bytes for RGB mode, giving you a unique visual representation <br>
  of your data.</strong></em><br>
  
  <br>
  <br>
  <h1> How to use this program ? </h1>
  <strong> Dependencies you need to install </strong> 
<ul>
  <li>OpenCV</li>
  <li>Compiler for C++</li>
</ul>
  <strong>Citation</strong> 
<ul>
  <li>Credit to: Luigi Pertoldi for the progress bar https://github.com/gipert/progressbar</li>
</ul>
<strong> How to use</strong> 
 <ol>
  <li>place you file into the resources folder <br> <img src="https://user-images.githubusercontent.com/102965306/235339068-e587eb80-0134-4049-b348-46e3d904cd5b.png" alt=""></li>
  <li>Compile the code using this command : <strong>g++ -o program main.cpp Utils.cpp Render.cpp ImageSpecs.cpp `pkg-config opencv4 --cflags --libs`</strong> </li>
  <li>Run the program <br> 
      Enter your file name and video specs <br>
  <img width="400" src="https://user-images.githubusercontent.com/102965306/235339272-40e878e2-6569-45d1-8f86-bf5a2ad3b47c.png" alt=""></li>
  
  <li>Wait for the program to finish and locate you video at the out folder <br>
  <img src="https://user-images.githubusercontent.com/102965306/235339406-2d618dee-e7dc-4237-82b8-47e8c5287c88.png" alt=""></li>
</ol>
<h1> Explanation </h1>
<em><strong> Think of it like storing data on a vinyl record that can be read with the right tool.</strong> </em>
<br>
<img width="400" src="https://user-images.githubusercontent.com/102965306/235340147-f973b8e9-faad-40fd-a047-30993a9a9f15.gif" alt="">

<em><strong>Since all files are made up from bytes or many 8 bits string <br>
and one byte can represent a number from 0 to 255, an RGB colour <br>
is made up by 3 int values from 0 to 255. This means that a pixel <br>
in a video of RGB mode contains 3 bytes or 24 bits <br>
<br>
On the other hand for GRAYSCALE (idk how to name this better lol) <br>
each pixel is made up from a single bit, 0 for white and 1 for 
black.<br>
<br>
This means that an RGB video with the same size to a GRAYSCALE video <br>
contains x24 time amount of data compare to GRAYSCALE video. However, <br>
the RGB video have a tendency to blur out it's images so it might be <br>
harder to read the data from the video compare to only black and white <br>
pixels in GRAYSCALE video.<br></strong> </em>


<h1> Final words </h1>

<em><strong><h>This project was inspired by DvorakDwarf and his https://github.com/DvorakDwarf/Infinite-Storage-Glitch which was written in Rust</h></strong></em>



