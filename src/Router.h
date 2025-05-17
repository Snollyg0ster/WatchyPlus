#include <map>
#include <string>
#include <vector>

#ifndef ROUTER_H
#define ROUTER_H

struct Route {
  std::string name;
  std::vector<std::string> routes;
};

using History = std::vector<Route>;

class Router {
private:
  History history;
  std::map<std::string, Route> routeMap;

public:
  Router(History routes, History restoredhistor);
  void setRoute(std::string name, bool clear);
  Route getRoute();
  bool back();
};

#endif // ROUTER_H