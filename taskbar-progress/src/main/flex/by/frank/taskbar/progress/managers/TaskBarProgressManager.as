package by.frank.taskbar.progress.managers
{
    import flash.external.ExtensionContext;

    /**
     * Created by IntelliJ IDEA.
     * @author Daniel R C Frank
     * @since 28/09/11
     * @version 1.0.0
     */
    public class TaskBarProgressManager
    {
        private var extension:ExtensionContext;

        public function TaskBarProgressManager()
        {
            extension = ExtensionContext.createExtensionContext("by.frank.taskbar.progress.TaskbarProgress", "");
        }

        public function setProgressState(state:int):void
        {
            extension.call("setProgressState", state);
        }

        public function setProgress(value:int, max:int):void
        {
            extension.call("setProgress", value,  max);
        }
    }
}
