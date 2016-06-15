#include "ofMain.h"
#include "ofxLiDAR.h"
#include <fstream>  // std::ifstream
#include <iostream> // std::cout

string ofxLiDAR::getLibLASVersion() {
    string ver = "libLAS version: " + liblas::GetVersion();
    if( liblas::IsLasZipEnabled() ) {
        ver += " (with compression)";
    } else {
        ver += " (compression NOT supported)";
    }
    return ver;
}

ofxLiDARLoader::ofxLiDARLoader() {
}

ofxLiDARLoader::~ofxLiDARLoader() {
}

void ofxLiDARLoader::copyHeader(const liblas::Header &hdr) {
  header.pointcount = hdr.GetPointRecordsCount();
  header.scalex     = hdr.GetScaleX();
  header.scaley     = hdr.GetScaleY();
  header.scalez     = hdr.GetScaleZ();
  header.offsetx    = hdr.GetOffsetX();
  header.offsety    = hdr.GetOffsetY();
  header.offsetz    = hdr.GetOffsetZ();
  header.maxx       = hdr.GetMaxX();
  header.maxy       = hdr.GetMaxY();
  header.maxz       = hdr.GetMaxZ();
  header.minx       = hdr.GetMinX();
  header.miny       = hdr.GetMinY();
  header.minz       = hdr.GetMinZ();
}

void ofxLiDARLoader::load(string fname) {
  std::ifstream ifs;
  // set exceptions to be thrown on failure
  ifs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try {
    ifs.open(fname, std::ios::in | std::ios::binary);

    liblas::ReaderFactory f;
    liblas::Reader reader = f.CreateWithStream(ifs);

    liblas::Header const& hdr = reader.GetHeader();
    copyHeader( hdr );

    while (reader.ReadNextPoint())
    {
        liblas::Point const& p = reader.GetPoint();
        points.push_back(ofPoint(p.GetX(), p.GetY(), p.GetZ() ));
    }
  } catch (std::system_error& e) {
    ofLogError() << e.code().message();
  }
} // load

// /////////////////////////////////////////////////////////////////////////////
ofxLiDARRecorder::ofxLiDARRecorder() {
}

ofxLiDARRecorder::~ofxLiDARRecorder() {
}

void ofxLiDARRecorder::create(string fname) {
}

void ofxLiDARRecorder::close() {
}

void ofxLiDARRecorder::addPoint(ofPoint pt) {
}

void ofxLiDARRecorder::addPoint(ofPoint pt, ofFloatColor ptc) {
}

void ofxLiDARRecorder::addPoints(vector<ofPoint> pts) {
}

void ofxLiDARRecorder::addPoints(vector<ofPoint> pts, vector<ofFloatColor> ptcs) {
}

