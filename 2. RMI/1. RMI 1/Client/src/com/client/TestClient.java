package com.client;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import com.interf.test.TestRemote;

/**
 * @author   Edmundo 146165
 * @version  0.5
 * @since    2015-02-25
 */
public class TestClient {

	public static final String RMI_ID = "TestRMI";
	/**
	 * Define el puerto en donde se encuentra el servidor.
	 */
	public static final int RMI_PORT = 8080;

	public static void main(String[] args) throws RemoteException, NotBoundException {
		Registry registry = LocateRegistry.getRegistry("localhost", RMI_PORT);
		TestRemote remote = (TestRemote) registry.lookup(RMI_ID);
		System.out.println(remote.test("123"));
		System.out.println(remote.test("test"));
        System.out.println(remote.multiplicar(20, 2));
        System.out.println(remote.palindromear("Anita lava la tina"));
        System.out.println(remote.palindromear("A cavar a Caravaca"));
        System.out.println(remote.palindromear("A mama Roma le aviva el amor a papa y a papa Roma le aviva el amor a mama"));


	}

}
