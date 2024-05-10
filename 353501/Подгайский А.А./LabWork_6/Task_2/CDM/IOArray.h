#ifndef C7BC9EB8_046C_4089_9071_0EC3B33B9AD8
#define C7BC9EB8_046C_4089_9071_0EC3B33B9AD8

#include "IOService.h"
#include <qtmetamacros.h>
class IOArray : public IOService {
  Q_OBJECT
public:
  using IOService::IOService;
  ~IOArray() override;

  static const char DELIM = '=';
  const QString FNAME = FILE_PREF + "_0.txt";

  int size = 0;
  double *array = nullptr;

protected:
  void initInput() override;
  void initOutput() override;
  QString getInstructions() override;


protected:
  void onEnterInput();

protected slots:
  void processOutput() override;
};

#endif /* C7BC9EB8_046C_4089_9071_0EC3B33B9AD8 */
