#ifndef DF9AA41E_6360_43E6_B21C_AEE2F492BBF1
#define DF9AA41E_6360_43E6_B21C_AEE2F492BBF1

#include <QLabel>
#include <QObject>
#include <QPlainTextEdit>
#include <qobjectdefs.h>
#include <qtextedit.h>
#include <qtmetamacros.h>

enum ServiceType {
  BOTH = 0,
  INP,
  OUT
};

class IOService : public QObject {

  Q_OBJECT

protected:
  ServiceType type = BOTH;
  
  QLabel *output;
  QPlainTextEdit *input;
  QLabel *instruction;

  const QString FILE_PREF = "ПодгайскийЛаб20";

public:
  IOService(QPlainTextEdit *inp, QLabel *outp, QLabel *instr,
            QObject *par = nullptr, ServiceType = BOTH);
  virtual ~IOService();

  void init();

  virtual QString getInstructions() = 0;

  virtual void initInput() = 0;
  virtual void initOutput() = 0;

  void clear();

protected slots:
  virtual void processOutput() = 0;
};

#endif /* DF9AA41E_6360_43E6_B21C_AEE2F492BBF1 */
