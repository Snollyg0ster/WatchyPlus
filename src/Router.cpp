#include <Router.h>

class Router {
private:
  std::vector<Route> history;
  std::map<std::string, Route> routeMap;

public:
  Router(std::vector<Route> routes) {
    for (Route r : routes) {
      routeMap[r.name] = r;
    }
  }

  Router(std::vector<Route> routes, std::string defaultRoute) {
    for (Route r : routes) {
      routeMap[r.name] = r;
    }

    setRoute(defaultRoute);
  }

  void setRoute(std::string name, bool clear = false) {
    if (clear)
      history.clear();
    history.push_back(routeMap.at(name));
  }

  Route getRoute() { return history.back(); }

  bool back() {
    if (history.size() < 2) {
      return false;
    }

    history.pop_back();
    return true;
  }
};