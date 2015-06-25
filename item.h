#ifndef ITEM_H__
#define ITEM_H__

//#include <iostream>

class item {
private:
  int x_;
  int y_;
public:
  item();
  item(int x, int y =0);
  item(const item& other);
  item(item&& other);
  ~item();

  item& operator=(const item& other);
  item& operator=(item&& other);

  std::ostream& print_on(std::ostream& stream) const;
};

inline std::ostream& operator<<(std::ostream& stream, const item& x) {
  return x.print_on(stream);
}
#endif