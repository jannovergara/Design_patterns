#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  // <p>hello</p>
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  printf("<p>%s</p>\n", text);

  // <ul><li>hello</li><li>world</li></ul>
  string words[] = { "hello", "world" };
  ostringstream oss;
  oss << "<ul>\n";
  for (auto w : words)
    oss << "  <li>" << w << "</li>\n";
  oss << "</ul>\n";
  printf(oss.str().c_str());

  getchar();
  return 0;
}