package by.frank.taskbar.progress.managers
{
    import flash.external.ExtensionContext;

    /**
     * Manage access to the Windows 7 Taskbar Progress API.
     * @author Daniel R C Frank
     * @since 28/09/11
     * @version 1.0.0
     */
    public class TaskBarProgressManager
    {
        private var extension:ExtensionContext;

        /**
         * Constructor
         */
        public function TaskBarProgressManager()
        {
            extension = ExtensionContext.createExtensionContext("by.frank.taskbar.progress.TaskbarProgress", "");
        }

        /**
         * Sets progress state.
         * @param state Use ProgressStateType constants to get possible types.
         * @see by.frank.taskbar.progress.managers.ProgressStateType
         */
        public function setProgressState(state:int):void
        {
            extension.call("setProgressState", state);
        }

        /**
         * Sets progress value,
         * @param current current value
         * @param max max value
         */
        public function setProgress(current:int, max:int=99):void
        {
            extension.call("setProgress", current,  max);
        }
    }
}