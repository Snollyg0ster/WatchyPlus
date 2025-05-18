#include <Router.h>

void Router::setRoute(std::string name, bool clear) {
  if (clear)
    history.clear();
  history.push_back(routeMap.at(name));
}

Router::Router(History routes, History restoredhistory,
               std::string defaultRoute) {
  for (Route r : routes) {
    routeMap[r.name] = r;
  }

  history = restoredhistory;

  if (history.size() == 0) {
    setRoute(defaultRoute);
  }
}

Route Router::getRoute() { return history.back(); }

bool Router::back() {
  if (history.size() < 2) {
    return false;
  }

  history.pop_back();
  return true;
}
