#ifndef IO_HPP
#define IO_HPP
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ReadWrite
{
  private:
    int Id;
    string Path;

  public:
    ReadWrite(int id, string path) : Id(id), Path(path) {}
    int GetId() { return Id; }                 // { return Id; }
    void SetId(int id) { Id = id; }            // { Id = id; }
    string GetPath() { return Path; }          //  { return Path; }
    void SetPath(string path) { Path = path; } //  { Path = path; }
    void ReadFile();
    void WriteFile();

    ~ReadWrite() {}
};
#endif
