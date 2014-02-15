(jde-project-file-version "1.0")

(jde-set-variables
 '(jde-global-classpath
   (quote
    ("$PROJECTS_HOME/bin/classes"
     "~/android-sdk/platforms/android-19/android.jar")))

 '(jde-sourcepath
   (quote
    ("$PROJECTS_HOME/src/com/jws/aua"
     "$PROJECTS_HOME/test/src/com/jws/aua")))

 ;; what should be put as java file header
 '(jde-gen-buffer-boilerplate
   (quote
    ("/*******************************************************************************"
     " * Copyright (c) 2012-2020 JWS"
     " * Jason Work Studio (JWS)"
     " *"
     " * All rights reserved."
     " *******************************************************************************/")))
 ;; sorting imports
 '(jde-import-auto-sort t)

 ;; Defines bracket placement style - now it is set according to SUN standards
 '(jde-gen-k&r t)

 '(user-full-name "enroute")
 '(user-mail-address "enroute.smth@gmail.com")
 )