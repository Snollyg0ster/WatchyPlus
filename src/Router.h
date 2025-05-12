#include <map>
#include <string>
#include <vector>

#ifndef ROUTER_H
#define ROUTER_H

struct Route {
  std::string name;
  std::vector<std::string> routes;
};

class Router {
private:
  std::vector<Route> history;
  std::map<std::string, Route> routeMap;

public:
  Router(std::vector<Route> routes);
  Router(std::vector<Route> routes, std::string defaultRoute);
  void setRoute(std::string name, bool clear);
  Route getRoute();
  bool back();
};

#endif // ROUTER_H