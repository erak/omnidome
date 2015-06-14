
#include <QApplication>
#include <omni/ui/GLDisplay.h>

/// Test for projector widget
int main(int ac, char* av[])
{
  /// Start gui
  QApplication _a(ac, av);
 
  omni::ui::GLDisplay _disp;

  _disp.show();

  return _a.exec();
}
