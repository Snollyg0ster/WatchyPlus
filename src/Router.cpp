#include <Router.h>

Router::Router(std::vector<Route> routes) {
  for (Route r : routes) {
    routeMap[r.name] = r;
  }
}

void Router::setRoute(std::string name, bool clear = false) {
  if (clear)
    history.clear();
  history.push_back(routeMap.at(name));
}

Router::Router(std::vector<Route> routes, std::string defaultRoute) {
  for (Route r : routes) {
    routeMap[r.name] = r;
  }

  setRoute(defaultRoute);
}

Route Router::getRoute() { return history.back(); }

bool Router::back() {
  if (history.size() < 2) {
    return false;
  }

  history.pop_back();
  return true;
}
