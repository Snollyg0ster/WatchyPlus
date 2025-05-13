#include <Router.h>

Router::Router(std::vector<Route> routes) {
  for (Route r : routes) {
    routeMap[r.name] = r;
  }
}

std::vector<Route> *Router::__getHistory() { return &history; }

void Router::setRoute(std::string name, bool clear = false) {
  history = *__getHistory();

  if (clear) {
    history.clear();
  }

  history.push_back(routeMap.at(name));
}

Router::Router(std::vector<Route> routes, std::string defaultRoute) {
  for (Route r : routes) {
    routeMap[r.name] = r;
  }

  if ((*__getHistory()).size() == 0) {
    setRoute(defaultRoute);
  }
}

Route Router::getRoute() { return history.back(); }

bool Router::back() {
  history = *__getHistory();

  if (history.size() < 2) {
    return false;
  }

  history.pop_back();

  return true;
}
