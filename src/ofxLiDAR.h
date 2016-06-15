#ifndef __OFXLIDAR_H__
#define __OFXLIDAR_H__

#include "ofMain.h"

#include <liblas/liblas.hpp>

using namespace std;

struct sLASHeader {
  unsigned long pointcount;
  double scalex;
  double scaley;
  double scalez;
  double offsetx;
  double offsety;
  double offsetz;
  double maxx;
  double maxy;
  double maxz;
  double minx;
  double miny;
  double minz;
};

class ofxLiDAR {
public:
    static string getLibLASVersion();
};

class ofxLiDARLoader {
public:
  ofxLiDARLoader();
  ~ofxLiDARLoader();

  void load(string fname);
  void copyHeader(const liblas::Header &hdr);

  sLASHeader header;
  
protected:
  vector <ofPoint> points;
  vector <ofFloatColor> colors;
};

class ofxLiDARRecorder {
public:
  ofxLiDARRecorder();
  ~ofxLiDARRecorder();

  void create(string fname);
  void close();

  void addPoint(ofPoint pt);
  void addPoint(ofPoint pt, ofFloatColor ptc);
  void addPoints(vector<ofPoint> pts);
  void addPoints(vector<ofPoint> pts, vector<ofFloatColor> ptcs);
};

#endif
