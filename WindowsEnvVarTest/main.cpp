#include <QCoreApplication>
#include <QString>
#include <iostream>

/**
 * Test code to get a environment variable in Windows
 */
int main(int argc, char* argv[]) {
	QCoreApplication app(argc, argv);

	const QString envVar = "path";	// the name of the evnironment variable for which we want the value
	char* pEnvVarVal = NULL;	// the value that will be return from the function

#ifdef _WIN32
		size_t envVarValSize;	// the returned size of the variable 
		errno_t envVarErrorCode = _dupenv_s(&pEnvVarVal, &envVarValSize, envVar.toLatin1());
		if(envVarErrorCode != 0 || envVarValSize == 0) { 
			// Handle error
			// Note: for some reason an unknown variable may return success 
			// with a 0 size value instead of returning an error
			std::cerr << "Unknown system variable " << envVar.toStdString() << std::endl;
		}
		else {
			// Print value of the variable
			std::cout << envVar.toStdString() << ":\t" << pEnvVarVal;
		}
#else	// Linux/Mac code
		pEnvVarVal = getenv(envVar.toLatin1());
#endif

	// Preven memory leak by cleaning up the variable's value after we are finished with it
	delete pEnvVarVal;
	pEnvVarVal = NULL;

	return app.exec(); // this will prevent the application for exiting immediately
}