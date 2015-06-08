#include <omni/ui/GLView.h>

#include <omni/Session.h>
#include <omni/util.h>

#include <QMouseEvent>


namespace omni
{
  namespace ui
  {
    GLView::GLView(QWidget* _parent) :
      QOpenGLWidget(_parent),
      session_(nullptr)
    {
    }

    GLView::~GLView()
    {
    }

    void GLView::free()
    {
    }

    float GLView::aspect() const
    {
      return (float)width() / height();
    }

    Session const* GLView::session() const
    {
      return session_;
    }

    void GLView::setSession(Session* _session)
    {
      session_=_session;
      update();
    }
      
    QPointF GLView::mousePosition() const
    {
      return mousePosition_;
    }

    void GLView::initializeGL()
    { 
      initializeOpenGLFunctions();
      glEnable(GL_DEPTH_TEST);
      glDepthFunc(GL_LEQUAL);
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glEnable(GL_LINE_SMOOTH);
      glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
      glEnable(GL_POINT_SMOOTH);
      glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
      glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
      glPolygonMode(GL_FRONT,GL_FILL);
      glPolygonMode(GL_BACK,GL_FILL);
      glEnable(GL_NORMALIZE);
      // fix outlines z-fighting with quads
      glPolygonOffset(1, 1);
    }

    void GLView::resizeGL(int _w, int _h)
    {
      _w = _w & ~1;
      _h = _h & ~1;
      glViewport(0, 0, (GLint)_w, (GLint)_h);
      glClearColor(0.0,0.0,0.0,1.0);
      update();
    }

    void GLView::paintGL()
    {
      if (!session_) return;

    }
      
    void GLView::mousePressEvent(QMouseEvent* event)
    {
      QOpenGLWidget::mousePressEvent(event);
      setFocus();
      if (!session_) return;
      mousePosition_ = event->pos();

      update();
    }
  }
}
