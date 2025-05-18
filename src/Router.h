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
  Router(std::map<std::string, Route> routes, History restoredhistory,
         std::string defaultRoute);
  void setRoute(std::string name, bool clear = false);
  Route getRoute();
  bool back();
};

#endif // ROUTER_H