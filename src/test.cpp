    #include <iostream>
    #include <fstream>
    using namespace std;
    main () {
     int filename;
      cout << "Enter file name"; cin >> filename;
        ofstream myfile;
        myfile.open("check_prob.txt");
        int i = 0;
      while(i<256)
      {              
      myfile <<i<< "\n";
      i++;
        
      }         
      myfile.close();
      return 0;
    }